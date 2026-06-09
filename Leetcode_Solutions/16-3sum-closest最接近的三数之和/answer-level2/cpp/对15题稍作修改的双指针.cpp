class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    
        int left,right;
        int temp=0;
        int flag=0;    //用来指示三数之和大于0还是小于0
        int closest = abs(target-nums[0]-nums[1]-nums[2]);
        
        if((target-nums[0]-nums[1]-nums[2])>0) flag=-1;
        else flag=1;
                   
        int numslen = nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<numslen;i++)
        {
            left = i+1;
            right = numslen-1;
            while(left<right)
            {
                if(nums[i]==target-nums[left]-nums[right]) return target;
                else if(nums[i]>target-nums[left]-nums[right])
                {
                    temp = (nums[i]+nums[left]+nums[right]) - target;
                    if(temp<closest)
                    {
                        closest = temp;
                        flag = 1;
                    }
                    right--;
                }
                else
                {
                    temp = target - (nums[i]+nums[left]+nums[right]);
                    if(temp<closest)
                    {
                        closest = temp;
                        flag = -1;
                    }
                    left++;
                }
            }
        }
        return (target+flag*closest);
    }
};