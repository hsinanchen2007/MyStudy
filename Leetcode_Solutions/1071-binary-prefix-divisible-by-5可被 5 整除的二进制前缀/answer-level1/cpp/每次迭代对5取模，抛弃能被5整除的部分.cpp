因为一个数中能被5整除的部分无论乘2多少次，最后还是能被5整除。所以可以抛弃掉这部分数。
每次迭代对5取模，抛弃能被5整除的部分。
```cpp
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int len = A.size(), num = 0;
        vector<bool> ans(len);
        for(int i = 0; i < len; ++i) {
            num = num * 2 + A[i];
            num %= 5;
            ans[i] = (num == 0);
        }
        return ans;
    }
};
```
