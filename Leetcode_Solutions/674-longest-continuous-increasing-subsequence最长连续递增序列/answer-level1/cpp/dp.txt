### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int max1=0;
        int j=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                max1=max(max1,i-j);
                j=i;
            }
        }
        int n=nums.size();
        max1=max(max1,n-j);
        return max1;
    }
};
```