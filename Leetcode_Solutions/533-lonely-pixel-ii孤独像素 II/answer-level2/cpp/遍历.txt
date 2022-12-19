1. 本题比较蛋疼，感觉也不需要什么技巧，就是题目有点难以理解.
2. 遍历比较即可。
```
class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        int r = picture.size();
        int c = picture[0].size();
        int res = 0;
        vector<int> countRow(r,0);
        vector<int> countColum(c,0);
        vector<string> row(r,"");
        unordered_map<int,vector<int>> blackColum;
        
        for(int i = 0; i < r; ++i){
            int count = 0;
            for(int j = 0;j < c; ++j){
                if(picture[i][j] == 'B'){
                    count++;
                }
                row[i].push_back(picture[i][j]);
            }
            countRow[i] = count;
        }
        
        for(int i = 0;i < c; ++i){
            int count = 0;
            for(int j = 0;j < r; ++j){
                if(picture[j][i] == 'B'){
                    count++;
                    blackColum[i].push_back(j);
                }
            }
            countColum[i] = count;
        }
        
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                if(countRow[i] == N && countColum[j] == N){
                    bool isSame = true;
                    for(int k = 0; k < blackColum[j].size(); ++k){
                        if(row[blackColum[j][k]] != row[i]){
                            isSame = false;
                            break;
                        }
                    }
                    if(isSame){
                        res++;
                    }
                }
            }
        }
        
        return res;
    }
};
```