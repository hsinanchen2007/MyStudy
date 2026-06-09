### 解题思路
令 `val` 作为数组的前 `i` 个数字的二进制数，则前 `i + 1` 个数字的二进制数是 `2 * val + A [i]`。
每当 `val` 值将要溢出时，可以只关注 `val` 值的最后一位数字。

### 代码
```cpp
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ans;
        int val = 0;
        for(int i=0; i<A.size(); ++i)
        {
            if(val > INT_MAX / 2)
            {
                val = val % 10; // 只关注 val 的最后一位数字
            }

            val = 2 * val + A[i];
            if(val % 5 == 0)
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
        return ans;
    }
};
```

### 复杂度分析
时间复杂度：$O(N)$，$N$ 为数组 $A$ 的元素个数。
空间复杂度：$O(1)$。
