### 解题思路
因为是循环数组，所以再在nums的后面追加一个nums数组，即可变成循环条件，
然后暴力求解即可。

### 代码

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> vecResult(nums.size(), 0);
        vector<int> newNums(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            newNums.push_back(nums[i]);
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            bool flag = false;
            for (int j = i + 1; j < newNums.size(); j++) {
                if (newNums[j] > nums[i]) {
                    vecResult[i] = newNums[j];
                    flag = true;
                    break;
                }
            }
            vecResult[i] = flag ? vecResult[i] : -1;
        }
        return vecResult;
    }
};
```