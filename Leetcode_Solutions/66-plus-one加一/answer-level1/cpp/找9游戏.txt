### 解题思路
- 主要是判别数字9

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // 判断溢出
        // 2147483648
        if(digits.size() == 0) return {}; // 特判
        int cur = digits.size()-1;
        // 在为9的情况下+1导致的连锁反应
        while(digits[cur] == 9){
            digits[cur] = 0;
            --cur;
            if(cur < 0) {
                digits[0] = 1;
                digits.push_back(0);
                return digits;
            }// 如果该数为第一个坐标点。位数需增加1
        }// 找到第一个小于9的数据如果该数不为第一个坐标点
        ++digits[cur];
        return digits;
    }
};
```