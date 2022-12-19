利用类似哈希的东西。
因为字符串的每一位都是字符，在编译器里使用ASCII码，即一个整数进行操作。
### 预处理
```cpp
book['I' - 64] = 1;
book['V' - 64] = 5;
book['X' - 64] = 10;
book['L' - 64] = 50;
book['C' - 64] = 100;
book['D' - 64] = 500;
book['M' - 64] = 1000;
```
然后，常规操作：
若该位小于下一位，则加下一位数值，减这一位数值，同时下一位跳过
否则，加这一位数值。
##### 注意！最后一位特判！
### 核心
```cpp
if(book[s[i] - 64] < book[s[i + 1] - 64])
    ans += book[s[i + 1] - 64] - book[s[i] - 64], i ++;
else
    ans += book[s[i] - 64];
```
### 完整代码

```cpp
int book[30];
class Solution {
public:
    int romanToInt(string s) {
        book['I' - 64] = 1;
        book['V' - 64] = 5;
        book['X' - 64] = 10;
        book['L' - 64] = 50;
        book['C' - 64] = 100;
        book['D' - 64] = 500;
        book['M' - 64] = 1000;
        int len = s.size(), ans = 0;
        for(int i = 0; i < len; i ++)
        {
            if(i == len - 1)
            {
                ans += book[s[i] - 64];
                continue;
            }
            if(book[s[i] - 64] < book[s[i + 1] - 64])
                ans += book[s[i + 1] - 64] - book[s[i] - 64], i ++;
            else
                ans += book[s[i] - 64];
        }
        return ans;
    }
};
```