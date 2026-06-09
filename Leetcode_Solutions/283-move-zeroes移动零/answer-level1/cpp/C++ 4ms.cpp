### 解题思路
双指针，当指针1不等于0时，将指针1的值赋给指针2

### 代码

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index=0;
        int length=nums.size();
        for(int i=0;i<length;++i){
            if(nums[i]!=0){
                nums[index]=nums[i];
                index++;
            }
        }
        for(int j=index;j<length;++j)
            nums[j]=0;
    }
};
```