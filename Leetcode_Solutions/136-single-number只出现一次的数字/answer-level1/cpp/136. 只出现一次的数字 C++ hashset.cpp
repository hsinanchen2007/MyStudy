### 解题思路
线性复杂度，但是空间复杂度O(n)

### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_set<int> numset;
        int result = 0;

        for (auto num : nums) {
            if (numset.count(num)) {
                numset.erase(num);
            } else {
                numset.insert(num);
            }
        }

        for (auto num : numset) {
            result = num;
        }

        return result;
    }
};
```