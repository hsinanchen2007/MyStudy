15题的扩展题
```
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int closetotarget=INT_MAX;
        int res;
        for(int i=0;i<n-1;i++)
        {
            int l=i+1;int r=n-1;
            while(l<r)
            {
                int sum=nums[i]+nums[r]+nums[l];
                if(abs(sum-target)<closetotarget)
                {
                    closetotarget=abs(sum-target);res=sum;
                }
                if(sum-target>0)
                    r--;
                else if(sum-target<0)
                    l++;
                else if(sum-target==0)
                    return sum;
            }
        }
        return res;
    }
};
```
