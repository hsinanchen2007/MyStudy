```
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1)return nums.size();
        if(nums.size() == 2)return nums[1] == nums[0] ? 1 : 2;
        int maxL;
        int last;  // 记录前一时刻状态，只有三种状态，大于 1， 小于 0， 等于 2；
        int cur;   // 当前时刻状态，与前一时刻不等且不为2时maxL++;
        if(nums[1] != nums[0])
        {
            last = nums[1] > nums[0] ? 1 : 0;
            maxL = 2;
        }
        else{
            maxL = 1;
            last = 2;  // 等于的情况下是2；
        }
        for(int i = 1; i < nums.size() - 1; i++)
        {
            if(nums[i + 1] > nums[i])
                cur = 1;
            else if(nums[i + 1] < nums[i])
                cur = 0;
            else
                cur = 2;
            if(cur != last && cur != 2)
            {
                maxL++;
                last = cur;
            }
        }

        return maxL;
    }
};
```
