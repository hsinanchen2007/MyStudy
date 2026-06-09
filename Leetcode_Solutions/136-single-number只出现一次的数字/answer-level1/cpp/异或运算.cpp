### 解题思路

1.任何数与0异或结果不变

2.两个相同数字的异或结果为0

3.异或运算有交换律，结合律


### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int re = 0;
        for(int i = 0;i < nums.size();i ++)
            re = re^nums[i];
        return re;
    }
};
```