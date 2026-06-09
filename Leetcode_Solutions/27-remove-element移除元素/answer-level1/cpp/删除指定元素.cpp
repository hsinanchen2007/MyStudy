### 解题思路
这道题一开始走进了误区,想着继续用双指针,但是观测对象搞错了,不应该再去看i而是看j

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0 || nums == null){
            return 0;
        }
        int i=0,j=0;
        for(;j<nums.size();j++){
            if(nums[j]!=val){
                nums[i]=nums[j];
                i++;
            }
        }
        return i;
    }
};
```