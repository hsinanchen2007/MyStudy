### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/3407326eae0204bf55d26bfa0058752b2b7761226cce1565c3121e30e3e6e684-image.png)


### 代码

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        int i = size-1;
        for(;i>0;i--){
            if(nums[i]<nums[i-1]){
                break;
            }
        }
        return nums[i];
    }
};
```