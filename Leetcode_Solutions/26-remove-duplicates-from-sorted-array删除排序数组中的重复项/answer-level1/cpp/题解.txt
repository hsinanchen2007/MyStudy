### 解题思路
由于是有序的数组，后面的数一定要比前面的大，所以遍历一遍，依次把后面的值赋值给前面的数组

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int cnt=1;
        int l=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[l])continue;
            else nums[++l]=nums[i];
        }
        return l+1;
    }
};
```