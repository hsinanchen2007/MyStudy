```
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>tritangle(numRows);
        if(numRows==0){
            return tritangle;
        }
        tritangle[0].push_back(1);
        for(int i=1;i<numRows;++i){
            tritangle[i].push_back(1);
            for(int j=1;j<i;++j){
                tritangle[i].push_back(tritangle[i-1][j-1]+tritangle[i-1][j]);
            }
            tritangle[i].push_back(1);
        }
        return tritangle;
    }
};
```
先特判一下numRows等于0的情况，再逐行求解。