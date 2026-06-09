### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int minvalue=INT_MAX;
        int index=0;
        vector<int> sum;
        for(int i=0;i<matrix.size();i++){
            int minvalue=INT_MAX;
            for(int j=0;j<matrix[i].size();j++){
                if(minvalue>matrix[i][j]){
                    minvalue=matrix[i][j];
                    index=j;
                }
            }
            int maxvalue=minvalue;
            for(int col=0;col<matrix.size();col++){
                if(maxvalue<matrix[col][index]){
                    maxvalue=matrix[col][index];
                }
            }
            if(minvalue==maxvalue){
                sum.push_back(minvalue);
            }
        }
        return sum;
        
    }
};
```