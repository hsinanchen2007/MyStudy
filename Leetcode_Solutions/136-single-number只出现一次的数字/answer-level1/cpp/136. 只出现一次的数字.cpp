### 解题思路
1.使用异或作为解题思路，异或就是不同出1，相同出0，异或也支持交换律。
2.初始化一个数字a= 0，任何数字与其异或都是数字本身，因此将数组中的所有数字累次与a异或，又因为相同的数字异或后会出0，所以最后a中的数字则为单次出现的数字
3.因为题目中表示数字只会出现一次或两次，因此可以使用异或的方法。

### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int a = 0;
    for(int i = 0;i < nums.size();i++){
        a ^= nums[i];
    }
    return a;
    }
};
```