### 解题思路
先得到二维数组A的行列值，然后先遍历行，把每一行的元素进行逆序，C++可以直接调用reverse()函数。然后在每一行遍历每一列，如果列值为1，则变为0，否则变为1.

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int row = A.size();
        int col = A.back().size();
        for(int i =0;i<row;i++){
            reverse(A[i].begin(),A[i].end());
            for(int j = 0;j<col;j++){
                if(A[i][j]==0) A[i][j]=1;
                else A[i][j]=0;
            }
        }
        return A;
    }
};
```