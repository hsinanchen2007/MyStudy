### 解题思路
直接模拟，本来想想下有没有数学方法，后来放弃了

### 代码

```cpp
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> matrix(n,vector<int>(m,0));
        int res=0;
        for(int i=0;i<indices.size();i++){
            int x=indices[i][0],y=indices[i][1];
            for(int j=0;j<m;j++){
                matrix[x][j]++;
            }
            for(int j=0;j<n;j++){
                matrix[j][y]++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]%2==1) res++;
            }
        }
        return res;
    }
};
```