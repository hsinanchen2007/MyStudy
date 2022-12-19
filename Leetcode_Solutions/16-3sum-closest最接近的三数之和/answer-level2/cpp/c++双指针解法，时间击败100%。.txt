class Solution {
public:
    //双指针法，先排序，再双指针。
    int threeSumClosest(vector<int>& nums, int target) {
        int ret =nums[0]+nums[1]+nums[2];
        //遍历的终止限制
        int size=nums.size()-2;
        sort(nums.begin(),nums.end());
        if(size==1)return ret;
        for(int i=0;i<size;++i)
        {
            int right=size+1;
            int left=i+1;
            int tempval=target-nums[i];
            int twosum;
            //pregap用于和nowgap比较上次移动和这次哪次更近。
            int pregap=abs(target-nums[i]-nums[left]-nums[right]);
            int presum,nowsum,nowgap;
            while(left<right)
            {   
                twosum=nums[left]+nums[right];
                if(twosum==tempval)return target;
                nowsum=twosum+nums[i];
                nowgap=abs(target-nowsum);
                if(nowgap>pregap)
                {
                    nowgap=pregap;
                    nowsum=presum;
                }
                if(twosum<tempval)++left;
                else --right;
                presum=nowsum;
                pregap=nowgap;
                    
            }
            ret=nowgap<abs(target-ret)?nowsum:ret;
        }
        return ret;
    }
};