```
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        //if(size<3)return NULL;
        int ans = nums[0]+nums[1]+nums[2];
        //ans表示返回值
        for(int i = 0; i < size-2; i++){
            int l = i + 1, r = size-1;
            while(l<r){
                int res = nums[i]+nums[l]+nums[r];
                //res表示当前3个数之和
                ans = abs(ans-target)<abs(res-target)?ans:res;
                if(ans == target)return ans;
                //加了上边这个判断是否相等之后返回的语句，20ms/8.4MB缩减为4ms/8.2MB
                if(res<target)l++;
                else r--;
            }
        }
        return ans;
    }
};
```
