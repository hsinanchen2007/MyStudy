### 解题思路
此处撰写解题思路

![image.png](https://pic.leetcode-cn.com/4d812a1e70aa933a4c62b076818064cb62ed64e026ce9aa8d19e7ca509157b5d-image.png)


### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1, -1};
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                if(count == 0) {
                    res[0] = i;
                } else {
                    res[1] = i;
                }
                count += 1;
            }
        }

        if(count == 1) {
            res[1] = res[0];
        }

        return res;
    }
};
```