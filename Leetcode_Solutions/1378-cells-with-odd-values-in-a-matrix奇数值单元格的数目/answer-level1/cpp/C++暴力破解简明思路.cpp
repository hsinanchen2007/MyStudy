### 解题思路
考虑到indices是一个多行两列的二维数组，我们只需要将行号和列与indices的值比较即可
### 代码

```cpp
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int >> res (n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<indices.size();k++){
                    if(i==indices[k][0]){
                        res[i][j]++;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<indices.size();k++) {
                    if (j == indices[k][1]) {
                        res[i][j]++;
                    }
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(res[i][j]%2!=0){
                    count++;
                }

            }
        }
        return count;
    }
};
```