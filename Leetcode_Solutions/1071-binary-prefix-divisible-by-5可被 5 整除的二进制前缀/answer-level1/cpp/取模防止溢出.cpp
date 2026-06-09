### 解题思路

### 代码

```cpp
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ans;
        int num = A[0];
        if(num % 5 == 0)
            ans.push_back(true);
        else
            ans.push_back(false);
        for(int i = 1 ; i < A.size() ; ++i)
        {
            num = (num << 1) % 5;
            num += A[i];
            if(num % 5 == 0)
            ans.push_back(true);
            else
            ans.push_back(false);
        }
        return ans;
    }
};
```