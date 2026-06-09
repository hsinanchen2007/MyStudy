**一个数组里面若负数为偶数个，没有0，则最大值为全体乘积，这就是递归的边界**
```
class Solution {
public:
    int help(vector<int> nums)
    {
        if(nums.empty())
            return INT_MIN;
        if(nums.size()==1)
            return nums[0];
        vector<int>::iterator iter=find(nums.begin(),nums.end(),0);
        if(iter==nums.end())
        {
            int neg_num=0;
            int rec=1;
            int left_position,right_position;
            for(auto i:nums)
            {
                if(i<0)
                    neg_num++;
                rec=rec*i;
            }
            if(neg_num%2==0)
            {
                return rec;
            }
            else
            {
                for(int i=0;i<nums.size();i++)
                {
                    if(nums[i]<0)
                    {
                        left_position=i;
                        break;
                    }
                }
                for(int i=nums.size()-1;i>=0;i--)
                {
                    if(nums[i]<0)
                    {
                        right_position=i;
                        break;
                    }
                }
                int left=help(vector<int>(nums.begin(),nums.begin()+right_position));
                int right=help(vector<int>(nums.begin()+left_position+1,nums.end()));
                return max(left,right);
            }
        }
        else
        {
            int left=help(vector<int>(nums.begin(),iter));
            int right=help(vector<int>(iter+1,nums.end()));
            return max(max(left,right),0);
        }
    }
    int maxProduct(vector<int>& nums) {
        return help(nums);
    }
};
```
