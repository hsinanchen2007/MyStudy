class Solution {
public:
    int length[1005][1005];
    int longestCommonSubsequence(string text1, string text2) {
        for(int i = 0; i < text1.size(); i++){
            for(int j = 0; j < text2.size(); j++){
                length[i][j] = 0;
            }
        }
        for(int i = 0; i < text1.size(); i++){
            for(int j = 0; j < text2.size(); j++){
                if(text1[i] == text2[j]){
                    length[i][j] = i == 0 || j == 0 ? 1 : length[i-1][j-1] + 1;
                }else{
                    if(i > 0 && j > 0) length[i][j] = max(length[i-1][j], length[i][j-1]);
                    else if (j > 0) length[i][j] = length[i][j-1];
                    else if(i > 0)length[i][j] = length[i-1][j];
                }
            }
        }
        int max = 0;
        for(int i = 0; i < text1.size(); i++){
            for(int j = 0; j < text2.size(); j++){
                if(length[i][j] > max){
                    max = length[i][j];
                }
            }
        }
        return max;
    }
};