### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0;
        int len = A.size();
        for(int i = 0;i< len-2;i++)
        {
            for(int j = i+1; j< len-1;j++)
            {
                if( A[i+1] - A[i] != A[j+1]-A[j])
                    break;    
                res++;   
            }
        }
        return res;
    }
};
```