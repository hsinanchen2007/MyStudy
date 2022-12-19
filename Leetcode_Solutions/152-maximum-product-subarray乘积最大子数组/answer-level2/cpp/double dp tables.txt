### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()<2)
            return nums[0];
        vector<int> dp_p(nums.size(),0);
        vector<int> dp_n(nums.size(),0);
        int result=nums[0];
        if(nums[0]>0)
            dp_p[0]=nums[0];
        else
            dp_n[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            int temp=getMax(nums,i,dp_p,dp_n);
            result=max(result,temp);
        }
        return result;
    }
    int getMax(vector<int>& nums,int index,vector<int>& dp_p,vector<int>& dp_n){
        if(nums[index]>0){
            dp_n[index]=nums[index]*dp_n[index-1];
            dp_p[index]=max(nums[index],nums[index]*dp_p[index-1]);
            return dp_p[index];
        }
        else{
            dp_n[index]=(dp_p[index-1]!=0)?nums[index]*dp_p[index-1]:nums[index];
            dp_p[index]=(dp_n[index-1]!=0)?nums[index]*dp_n[index-1]:0;
            return (dp_p[index]!=0)?dp_p[index]:nums[index];
        }
    }
};
```