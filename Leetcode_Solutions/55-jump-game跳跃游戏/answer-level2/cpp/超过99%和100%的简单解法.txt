判断当前位置的值与位置和位置值之和的大小
```
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();int j=0;int ma=0;
        if(n==1&&nums[0]==0){
            return true;
        }
        for(int i=0;i<n;++i){
            j=i+nums[i];
            ma=max(ma,j);
            if(nums[i]!=0){
                continue;
            }
            else{
                if(ma<=i&&i!=n-1){
                    return false;
                }
                else{
                    continue;
                }
            }

        }
        return true;
    }
};
```
