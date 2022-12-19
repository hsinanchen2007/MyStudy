### 解题思路
把边界强转成长整形，否则会溢出

### 代码

```cpp
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper)
    {
        vector<string> result;
        if (nums.empty() || nums.back() < lower || nums.front() > upper) {
            result.push_back((lower == upper) ? to_string(lower) : to_string(lower) + "->" + to_string(upper));
            return result;
        }

        int start, end;
        string temp;

        temp = makeRange((long long)(lower) - 1, nums[0]);
        if (!temp.empty()) {
            result.push_back(temp);
        }

        for (int i = 0; i + 1 < nums.size(); ++i) {
            temp = makeRange(nums[i], nums[i + 1]);

            if (!temp.empty()) {
                result.push_back(temp);
            }
        }

        temp = makeRange(nums.back(), (long long)(upper) + 1);
        if (!temp.empty()) {
            result.push_back(temp);
        }
        
        return result;
    }

    string makeRange(long long start, long long end)
    {
        start = start + 1;
        end = end - 1;

        if (start > end) {
            return "";
        } else if (start < end) {
            return to_string(start) + "->" + to_string(end);
        } else {
            return to_string(start);
        }
    }
};
```