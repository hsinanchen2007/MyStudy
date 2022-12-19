多数在计数过程中的count在加减之后肯定是大于0的
```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c,count=1;
        c=nums[0];
        for(int i=1;i<nums.size();i++)
            if(nums[i]==c)
                count++;
            else
                if(count>0)
                    count--;
                else
                {
                    c=nums[i];
                    count=1;
                }    
        if(count>0)
             for(int i=count=0;i<nums.size();i++)
                 if(nums[i]==c)
                     count++;
        if(count>nums.size()/2)
            return c;

        return 0;

    }
};
```
