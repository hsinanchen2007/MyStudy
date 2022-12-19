### 解题思路
如果是奇数，直接返回奇数个单字符
如果是偶数，就是1个字符 + n - 1个奇数字符

### 代码

```cpp
class Solution {
public:
    string generateTheString(int n) {
        if ((n % 2) == 1) {
            return string(n, 'a');
        }
        return string(n - 1, 'a') + "b";
    }
};
```