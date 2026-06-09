### 解题思路
1.missing 和所有的i指针以及i指针对应存储的数做异或运算。
2.因为i中产生所有可能的数字，两个相同的数做异或处理肯定除0，因此当数组中缺少的那个数字必定会无法与i中的数字进行匹配成0。
3.因此循环完后，missing中的数字就是缺少的数字。

### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
            int missing = nums.size();
    for(int i = 0;i < nums.size();i++){
        missing ^= i ^ nums[i];
    }
    return missing;
    }
};
```