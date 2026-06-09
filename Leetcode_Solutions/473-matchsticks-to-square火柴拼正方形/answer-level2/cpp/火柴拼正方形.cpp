### 解题思路
能够找到三次组合累计和为边长的数的集合则可以拼成正方形

### 代码

```cpp
class Solution {
    
public:
    int len;
    bool findCombineN(vector<int>& nums,int edge,int begin){
        for(int i=begin;i>=0;i--){
            if(nums[i]>0 && nums[i]<=edge){
                int need=edge-nums[i];
                if(need==0){
                     nums[i]*=(-1);
                    return true;
                }
                nums[i]*=(-1);
                bool found=findCombineN(nums,need,i-1);
                if(found){
                    return true;
                }
                nums[i]*=(-1);
                    
            }
        }
        return false;
    }
    bool makesquare(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        len=nums.size();
        float edge=1.0*sum/4;
        if(len<4 || floor(edge)!=edge)return false;
        sort(nums.begin(),nums.end());
        if(nums[len-1]>edge)return false;
        for(int i=0;i<3;i++)
            if(!findCombineN(nums,edge,len-1))
                return false;
        return true;
    }
};
```