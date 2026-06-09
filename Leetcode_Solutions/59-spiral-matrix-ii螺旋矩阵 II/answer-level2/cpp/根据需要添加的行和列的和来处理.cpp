### 解题思路
对于mxn或者nxn，遍历的行和列的总和都是有规律的，根据这个总和来确定每一步的变换。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> r(n,1);
        vector<vector<int>> res(n,r);
        if(n==1){
            return res;
        }
        int len = 2*n - 1;
        int i = 0;
        int j = 0;
        for(int x=0;x<len;x++){
            int y = x%4;
            int c = (x+1)/4;
            switch (y) {
                case 0:
                    for(j=j+1;j<n-c;j++){
                        res[i][j] = res[i][j-1]+1;
                    }
                    j--;
                    break;
                case 1:
                    for(i=i+1;i<n-c;i++){
                        res[i][j] = res[i-1][j]+1;
                    }
                    i--;
                    break;
                case 2:
                    for(j=j-1;j>=c;j--){
                        res[i][j] = res[i][j+1]+1;
                    }
                    j++;
                    break;
                default:
                    for(i=i-1;i>=c;i--){
                        res[i][j] = res[i+1][j]+1;
                    }
                    i++;
                    break;
            }
        }
        return res;
    }
};
```