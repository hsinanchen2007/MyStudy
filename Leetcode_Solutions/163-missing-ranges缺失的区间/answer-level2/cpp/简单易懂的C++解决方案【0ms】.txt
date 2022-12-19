### 解题思路
这里返回的区间（range）都是闭合的，确定一个区间只需要确定其开始`start`和结束`end`。一开始我们将`start`初始化为`lower`，然后遍历
整个数组，`end`的值为当前值`n`减1，这里需要注意的是当前值可能为`INT_MIN`，这意味着减1会导致溢出，此时`lower`亦为`INT_MIN`，我们只需要令`start = n + 1`，然后接着考察下一个数。当`start < end`时我们得到一个形如`"start->end"`的答案，当它们相等时得到形如`"start"`的答案。

另外一个注意的地方是当`n == upper`时我们就可以停下来了，但我们需要一个标记已确定后续是否需要添加区间`[start,upper]`。

### 代码

```cpp
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int start = lower;
        int end;
        auto range = [](int a, int b) { return to_string(a) + "->" + to_string(b); };
        bool flag = false;
        for (auto n : nums) {
            if (n == INT_MIN) {
                start = n + 1;
                continue;
            }
            end = n - 1;
            if (start < end) {
                res.push_back(range(start, end));
            } else if (start == end) {
                res.push_back(to_string(start));
            }
            if (n == upper) {
                flag = true;
                break;
            }
            start = n + 1;
        }
        if (!flag) {
            if (start < upper) res.push_back(range(start, upper));
            else if (start == upper) res.push_back(to_string(start));
        }
        return res;
    }
};
```