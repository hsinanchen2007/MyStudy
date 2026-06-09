### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //计数0
        // int count=0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==0){
        //         nums.erase(nums.begin()+i);
        //         i--;
        //         count++;
        //     }
        // }
        // while(count){
        //     nums.insert(nums.end(),0);
        //     count--;
        // }

        // int len=nums.size();
        // int j=0;
        // for(int i=0;i<len;i++){
        //     if(nums[i]!=0)
        //         nums[j++]=nums[i];
        // }
        // for(;j<len;j++) 
        //     nums[j]=0;

        //官方题解
        for(int i=0,j=0;i<nums.size();i++)
            if(nums[i]!=0)
                swap(nums[j++],nums[i]);
            
    }
};
```