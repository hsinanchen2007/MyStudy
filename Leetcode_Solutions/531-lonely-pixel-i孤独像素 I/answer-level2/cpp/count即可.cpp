统计行与列中存在‘B’的个数。
```
class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int row = picture.size();
        int colum = picture[0].size();
        int ans = 0;
        vector<int> rowCount(row,0);
        vector<int> columCount(colum,0);
        
        for(int i = 0;i < row; ++i){
            for(int j = 0;j < colum; ++j){
                if(picture[i][j] == 'B'){
                    rowCount[i]++;
                    columCount[j]++;
                }
            }
        }
        
        for(int i = 0;i < row; ++i){
            for(int j = 0;j < colum; ++j){
                if(picture[i][j] == 'B'&&
                   rowCount[i] == 1&&
                   columCount[j] == 1){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
```