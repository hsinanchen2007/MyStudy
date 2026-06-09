### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //前n项积可否是一个思路？
        vector<int> dpmax(nums.size());
        vector<int> dpmin(nums.size());
        dpmax[0]=nums[0];
        dpmin[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>0){
                if(dpmax[i-1]>0) dpmax[i]=dpmax[i-1]*nums[i];
                else dpmax[i]=nums[i];
                if(dpmin[i-1]<=0) dpmin[i]=dpmin[i-1]*nums[i];
                else dpmin[i]=nums[i];
            }
            else if(nums[i]==0){
                dpmax[i]=0;
                dpmin[i]=0;
            }
            else{
                if(dpmin[i-1]<=0) dpmax[i]=dpmin[i-1]*nums[i];
                else dpmax[i]=nums[i];
                if(dpmax[i-1]>0) dpmin[i]=dpmax[i-1]*nums[i];
                else dpmin[i]=nums[i];
            }
        }
        int max=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(max<dpmax[i]) max=dpmax[i];
        }
        return max;
    }

};
```