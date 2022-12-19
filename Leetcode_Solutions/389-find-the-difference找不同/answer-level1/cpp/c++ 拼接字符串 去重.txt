### 解题思路
考虑到s与t只有一个字符差，考虑用类似数组从找出唯一一个不重复的数字思路
1. 首先拼接s+t
2. 利用异或运算 a ^ b ^ a = b，重复的字符异或后均消失，剩余的即为添加字符

### 代码

```cpp
class Solution {
public:
    char findTheDifference(string s, string t) {
        string tmp = s + t;
        int value = 0;
        for (int i = 0; i < tmp.size(); ++i) {
            value ^= tmp[i];
        }
        return (char)value;
    }
};
```