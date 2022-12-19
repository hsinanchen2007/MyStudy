```
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int arr[n][m];
        memset(arr,0,m*n*sizeof(int));
        for(int i = 0; i < indices.size(); i++){
            int x = indices[i][0];
            int y = indices[i][1];
            for(int j = 0; j < m; j++){ //indices对应的 行 的所有元素都加1
                arr[x][j]++;
            }
            for(int j = 0; j < n; j++){ //indices对应的 列 的所有元素都加1
                arr[j][y]++;
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++){// 计算奇数的个数
            for(int j = 0; j < m; j++){
                if(arr[i][j]%2 != 0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
```
![1.png](https://pic.leetcode-cn.com/c6eb484fb0856cfa6426fd6bcee124e70b977393e609f3ef9b65be82800f2ff9-1.png)
