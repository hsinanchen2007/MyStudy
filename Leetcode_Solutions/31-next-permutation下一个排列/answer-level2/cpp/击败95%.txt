### 解题思路

### 代码

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len=nums.size();
        if(len==1)return;
        int l=0,r=0;
        for(int i=len-1;i>1;i--){
            if(nums[i]>nums[i-1]){
                l=i-1;
                r=i;
                break;
            }
        }
        if(l==r){
            if(nums[0]>=nums[1])sort(nums.begin(),nums.end());
            else {
                int m=nums[1],t=1;
                for(int i=2;i<len;i++){
                    if((nums[i]>nums[0])&&(nums[i]<m)){t=i;m=nums[i];}
                }
                int temp=nums[t];
                nums[t]=nums[0];
                nums[0]=temp;
                sort(nums.begin()+1,nums.end());
            }
        }
        else{
            int temp=nums[r]-nums[l];
            int r1=r;
            for(int i=r+1;i<len;i++){
                if((nums[i]>nums[l])&&(nums[i]-nums[l]<temp)){
                    temp=nums[i]-nums[l];
                    r1=i;
                }
            }
            int temp1=nums[r1];
            nums[r1]=nums[l];
            nums[l]=temp1;
            sort(nums.begin()+l+1,nums.end());
        }
    }
};
```