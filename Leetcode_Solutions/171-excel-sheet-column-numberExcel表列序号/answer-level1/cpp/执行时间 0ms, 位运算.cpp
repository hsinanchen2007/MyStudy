### 解题思路
用多次移位运算替换乘法。

### 代码

```cpp
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0 ;
        for(int i = 0;i<s.size();++i){
            res = (res<<4) + (res<<3) + (res<<1) + (s[i] - '@');// << 优先级比 + 低
        } 
        return res;
    }
};
```

###截图
![解题.jpg](https://pic.leetcode-cn.com/6031a5aa7e72232105e4c3f2ea11d08716d777524b9ac875876dd98d7bff1368-%E8%A7%A3%E9%A2%98.jpg)
