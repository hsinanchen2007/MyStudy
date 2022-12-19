![1.png](https://pic.leetcode-cn.com/009b16fc124727b341cc71f7c98bad4d127701c8da88aefeda9e17c8ebb7a224-1.png)

### 代码

```cpp
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        for(int i=0,j=0;j<A.size();++j)
            if((A[j] & 1) == 0)swap(A[i++],A[j]);
        
        return A;
    }
};
```