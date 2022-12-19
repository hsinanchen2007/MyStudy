```
class Solution {
public:
     //其实每一次只需要判断当前的最大值是否被更新掉
        //每一次滑动窗口移动时，都将会淘汰掉滑动窗口最左边的值，并且加入滑动窗口右边的值
        //这个时候判断淘汰掉的值：如果是最大的，将会重新寻找最大值，如果不是->
        // 判断此时加入的值： 如果比最大值还要大，更新最大值，说明此时最大值为最大值
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> v;
        if(nums.size()==0 || k==0)
            return v;
        v.resize(n-k+1);
        int maxc=nums[0];
        for(int i=0;i<k;++i)
            if(maxc<nums[i])
                maxc=nums[i];
        v[0]=maxc;
        for(int i=1;i<n-k+1;++i)
        {
            if(maxc==nums[i-1])
            {
                maxc=nums[i];
                //说明此时需要重新更新
                for(int j=i;j<i+k;++j)
                    if(maxc<nums[j])
                        maxc=nums[j];
                v[i]=maxc;
            }
            else
            {
                if(maxc<nums[i+k-1])
                    maxc=nums[i+k-1];
                v[i]=maxc;
            }
        }
        return v;    
    }
};
```
