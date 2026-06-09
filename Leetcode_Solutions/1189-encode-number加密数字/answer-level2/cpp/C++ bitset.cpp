### 解题思路
用bitset转换数字为二进制字符串

![图片.png](https://pic.leetcode-cn.com/cc9700704f030cca9d69a02eca2dd9ab21a776f7286104988eb6b1da976f57fa-%E5%9B%BE%E7%89%87.png)


### 代码

```cpp
class Solution {
public:
    string encode(int num) {
        if (num == 0) {
            return string();
        }
        // 规律是: num + 1的二进制字符串去掉第一个'1'
        bitset<32> bs(num + 1);
        string str = bs.to_string();
        return str.substr(str.find('1') + 1);
    }
};
```