### 解题思路
交换律：a ^ b ^ c <=> a ^ c ^ b

任何数于0异或为任何数 0 ^ n => n

相同的数异或为0: n ^ n => 0

### 代码

```cpp
class Solution {
private:
public:
    int singleNumber(vector<int>& nums) {
        int num = 0;
        for(int i=0;i<nums.size();++i){
            num = num ^ nums[i];
        }
        return num;
    }
};
```