```c++
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,int>l,r,cnt;
        int size=nums.size();
        // 记录最大频数
        int degree=0;
        for (int t=0;t<nums.size();t++){
            int d=nums[t];
            if (l.find(d)==l.end())
                l[d]=t;
            r[d]=t;
            cnt[d]++;
            if (cnt[d]>degree)
                degree=cnt[d];
        }
        
        int ans=size;
        for (auto a : nums){
            if (cnt[a]==degree){
                ans=min(r[a]-l[a]+1,ans);
            }
        }
        return ans;
    }
};
```
