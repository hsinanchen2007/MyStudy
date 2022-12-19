### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() < 2) //没必要
        {
            return;
        }
        int i = 0, j = 0;
        while (i < nums.size() && j < nums.size())
        {
            while (i < nums.size() && nums[i] != 0) //找下一个最小位置的0
            {
                i++;
            }
            j = j == 0 ? i + 1 : j + 1;//j第一次从i+1开始，以后从j+1开始
            while (j < nums.size() && nums[j] == 0) //找下一个非0位置
            {
                j++;
            }
            if (i >= nums.size() || j >= nums.size())   //超了
            {
                return;
            }
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
    }
};
```