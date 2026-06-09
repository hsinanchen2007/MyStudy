### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int temp;
        for (int i = 0; i<A.size(); i++)
        {
            int k = A[i].size()-1;
            for (int j = 0; j<= A[i].size()/2;j++)
            {
                if (j<=k)
                {
                    temp=1-A[i][k];
                    A[i][k]=1-A[i][j];
                    A[i][j]=temp;
                    k--;
                }
                else
                {
                    break;
                }
                
            }
        }
        return A;
    }
};
```