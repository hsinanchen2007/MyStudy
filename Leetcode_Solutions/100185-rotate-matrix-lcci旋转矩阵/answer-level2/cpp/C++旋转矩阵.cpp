### 解题思路
![image.png](https://pic.leetcode-cn.com/559aa45b511bf8d2b908faa728965b277bd8ec8ab7b0418cc62628b6fd9903a7-image.png)
纪念一下双百

先转置，再reverse每一行

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m<=1)return;
        for(int i=0; i<m; i++){
            for(int j=i; j<m; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0;i<m;i++){
            reverse(matrix[i].begin(),matrix[i].end()) ;
        }
    }
};
```