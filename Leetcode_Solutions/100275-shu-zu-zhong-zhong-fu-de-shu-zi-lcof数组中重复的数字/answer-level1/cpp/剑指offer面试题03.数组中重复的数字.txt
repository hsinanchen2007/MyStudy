### 解题思路
由题意得：nums里的数字都在0~n-1的范围内，
所以用一个和nums等长的数组用来计数。
### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int arr[nums.size()] = {0};
        for (int i = 0; i < nums.size(); i++) {
            arr[nums[i]]++;
            if (arr[nums[i]] > 1) {
                return nums[i];
            }
        }
        return 0;
    }
};
```