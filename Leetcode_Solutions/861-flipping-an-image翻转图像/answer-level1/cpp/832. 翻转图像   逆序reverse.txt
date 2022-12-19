### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(int i=0;i<A.size();i++){
            reverse(A[i].begin(),A[i].end());//逆序
            for(int j=0;j<A[i].size();j++){
                if(A[i][j]==0)//交换
                    A[i][j]=1;
                else
                    A[i][j]=0;
            }
        }
        return A;
    }
};
```