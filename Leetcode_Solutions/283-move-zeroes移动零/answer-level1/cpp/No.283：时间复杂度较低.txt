# **C++频道：**

![image.png](https://pic.leetcode-cn.com/5dda74a6e1f67407119e06c73d347cdb253c8d23df2ea47e589861c3da9bc549-image.png)


```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;

        if(!nums.empty())
            for(int j=0; j<nums.size(); j++)
                if(nums[j] != 0){
                    nums[i] = nums[j];
                    ++i;
                }
            for(int j=i; j<nums.size(); j++)
                nums[j] = 0;
    }
};
```
