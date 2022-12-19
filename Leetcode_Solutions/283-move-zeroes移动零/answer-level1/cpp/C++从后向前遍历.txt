从后向前遍历，依次把遇到的0移动到最后
```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        int i = 0;
        int size = nums.size();
        for (j = size - 2; j >= 0; j--)
        {
            i = j;
            while (i < size - 1 && nums[i] == 0 && nums[i+1] != 0)
            {
                nums[i] = nums[i+1];
                nums[i+1] = 0;
                i++;
            }
        }
    }
};
```