### 解题思路
快排思想，双指针遍历。O(n)。

### 代码

```cpp
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {

        for(int i=0,j=0; j<A.size(); j++)
            if(A[j]%2==0) swap(A[i++],A[j]);

        return A;
    }
};
```