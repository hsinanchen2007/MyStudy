方法一 暴力
```
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int mindis,ans;
        mindis=abs(nums[0]+nums[1]+nums[2]-target);
        ans=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size()-1;i++){
            for(int k=i+1;k<nums.size()-1;k++){
                for(int j=nums.size()-1;j>k;j--){
                    if(abs(nums[i]+nums[j]+nums[k]-target)<mindis){
                        ans=nums[i]+nums[j]+nums[k];
                        mindis=abs(ans-target);
                    }
                }
            }
        }
        return ans;
    }
};
```
方法二 双指针
```
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size();i++) {
            int st=i+1, ed=nums.size()-1;
            while(st<ed) {
                int sum=nums[st]+nums[ed]+nums[i];
                if(abs(target-sum)<abs(target-ans)) ans = sum;
                if(sum == target) return ans;
                else if(sum < target) st++;
                else ed--;
            }
        }
        return ans;
    }
};
```

