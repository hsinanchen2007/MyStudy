### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()<2)return nums.size();
        vector<int> count(nums.size(),0);
        count[0]=nums[0];
        int end=0;
        for(int num:nums){
            int i=0,j=end;
            while(i<j){
                int mid=i+(j-i)/2;
                if(count[mid]<num)i=mid+1;
                else j=mid;
            }
            count[i]=num; 
            if(j==end)
                end++;
        }
        return end;
    }
};
```