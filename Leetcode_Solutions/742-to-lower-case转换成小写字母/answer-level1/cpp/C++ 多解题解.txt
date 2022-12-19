## 思路1
利用ASCII值大小写之间相差32的性质，遇到大写的字母，加上32就是相应的小写字母。
```cpp
class Solution {
public:
    string toLowerCase(string str) {
        int len = str.size();
        for(int i = 0; i < len; ++ i){
            if(str[i] <= 'Z' && str[i] >= 'A'){
                str[i] = str[i] + 32;
            }
        }
        return str;
    }
};
```
## 思路2 
使用哈希映射，打表，将大写的字母作为key， 小写字母作为value，遇到key，用相应key的value赋值。

## 思路3
位运算
根据评论区@Alfeim的总结：
大写变小写、小写变大写 : 字符 ^= 32;
大写变小写、小写变小写 : 字符 |= 32;
小写变大写、大写变大写 : 字符 &= -33;
## 思路4
使用内置函数tolower()，但是既然在训练算法，那就建议不要使用内置函数。
