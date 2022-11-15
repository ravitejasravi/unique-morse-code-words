class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        vector<string> MorseCode{".-","-...","-.-.","-..",".","..-.","--.","....","..",
                                    ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
                                    "...","-","..-","...-",".--","-..-","-.--","--.."};

        unordered_map<int, string> MorseCodeWithAlpha;
        unordered_map<string, int> exists;

        int ascii = 97;
        int transformation = 0;

        for(int i = 0; i < 26; i++)
            MorseCodeWithAlpha[ascii++] = MorseCode[i];
            
        for(int i = 0; i < words.size(); i++){

            string WordToMorse = "";

            for(int j = 0; j < words[i].length(); j++)
                WordToMorse += MorseCodeWithAlpha[(int)words[i][j]];
 
            if(exists[WordToMorse] <= 0)
                transformation += 1;

            exists[WordToMorse] += 1;

        }

        return transformation;
            
    }
};