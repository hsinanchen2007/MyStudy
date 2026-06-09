```
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        bool hasSet = false;  //贪心算法，模拟改变一个数的行为
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])
            {
                if(hasSet)    //机会只有一次，用完了，失败。
                    return false;
                hasSet = true;
                //有两种方法可以保持递增，因为是保持递增，所以“减小前一个数”是相对于“增加当前数”的更优方案
                if(i<2||nums[i]>=nums[i-2])  //优先设置前一个数，保证递增。
                    nums[i-1] = nums[i];
                else
                    nums[i] = nums[i-1];  //前一个设置不了，只能增加当前值，保持递增
            }
        }
        return true;
    }
};
```
