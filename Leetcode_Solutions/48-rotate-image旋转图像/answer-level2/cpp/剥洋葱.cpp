### 解题思路
思路上更像一道数学题
主要有以下几个困难
- 原地旋转下如何避免数据被覆盖
- 以何种方式迭代旋转
- ans
- 找到向右旋转的兑换方式，两两调换
- 一层，一层拨开我的心

### 代码
0ms

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 按照圈数循环
        // 旋转对应位置元素
        int i=0 ,j=matrix.size()-1;
        while(i<j){
            for(int l=i; l<j; ++l){
                int k = j-l+i;
                swap(matrix[i][l], matrix[l][j]);
                swap(matrix[j][k], matrix[k][i]);
                // 对位互换 (i,l) -> (l,j) (j,j-l + i)->(j - l + i,i)
                swap(matrix[i][l], matrix[j][k]);// 对角线互换 (i,l) -> (j,j-l)
            }// 对四个位置的值进行旋转
            ++i;
            --j;
        }
    }
};
```