### 解题思路
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :6.9 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution
{
public:
    int firstMissingPositive(const vector<int> &nums)
    {
        unordered_set<int> rec;
        for (auto &el : nums)
            if (el > 0)
                rec.insert(el);
        for (int i = 1; i < INTMAX_MAX; i++)
            if (rec.find(i) == rec.end())
                return i;
        return -1;
    }
};
```