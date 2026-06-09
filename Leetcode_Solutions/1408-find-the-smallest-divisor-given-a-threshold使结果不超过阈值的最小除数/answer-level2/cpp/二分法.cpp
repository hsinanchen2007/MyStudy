```
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left=1,right=1;
        for(int i=0;i<nums.size();++i){
            right=max(right,nums[i]);
        }
        int ans=right;
        while(left<=right){
            int mid=(left+right)/2;
            int temp=0;
            for(int i=0;i<nums.size();++i){
                temp+=nums[i]%mid==0?0:1;
                temp+=nums[i]/mid;
            }
            //cout<<mid<<"   "<<temp<<endl;
            if(temp<=threshold){
                right=mid-1;
                ans=min(ans,mid);
            }
            else if(temp>threshold){
                left=mid+1;
            }
        }
        return ans;

    }
};
```

