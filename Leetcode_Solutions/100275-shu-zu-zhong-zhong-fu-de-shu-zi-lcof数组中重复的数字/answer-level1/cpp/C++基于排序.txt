### 解题思路

对原来对数组进行排序，然后遍历数组，如果当前元素和下一个元素相同，则返回结果。


### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int res;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2;i++){
            if (nums[i] == nums[i+1]){
                res = nums[i];
                break;
            }
        }
    return res;    
    }
};
```

估计是没几个人用C++？最终击败了100%的人

![image.png](https://pic.leetcode-cn.com/fbb3fe734785be14b3d8decb3511f6f5c9af7813f2e3f2f8450748d831406bd8-image.png)
