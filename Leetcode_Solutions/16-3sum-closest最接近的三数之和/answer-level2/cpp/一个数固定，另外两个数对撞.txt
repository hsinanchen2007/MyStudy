1.暴力算法；
2.我暂时想到的，和三数之和思路基本一样，代码如下：

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minnum, sum;
        if( nums.size() > 2 )
        {
            minnum = abs( nums[0]+nums[1]+nums[2]-target );
            sum = nums[0]+nums[1]+nums[2];
        }
        else
            return -1;
        sort( nums.begin(), nums.end() );
        for( int i = 0; i < nums.size(); i++ )
        {
            int left = i+1, right = nums.size()-1;
            while( left < right )
            {
                int diff = nums[i]+nums[left]+nums[right]-target;
                if( minnum > abs(diff) )
                {
                    minnum = abs( diff );
                    sum = nums[i]+nums[left]+nums[right];
                }
                if( diff > 0 )
                    right--;
                else
                    left++;
            }
        }
        return sum;
    }
};