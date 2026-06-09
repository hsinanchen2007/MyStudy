1. 遍历数组，如果nums[i]等于1，则cur++;
2. 若nums[i]不等于1，则max等于max与cur的最大值,cur置为0
3. 返回max与cur的最大值
``` C++
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.empty()) return 0;
        int max=0,cur=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=1)
            {
                max=(cur>max)?cur:max;
                cur=0;
            }
            else
                cur++;
        }
        return (cur>max)?cur:max;
    }
};
```