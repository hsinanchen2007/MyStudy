### 解题思路
- 题目说不要使用数据结构，位运算登场
- 1位移n位`&`操作，只获取该位，接着`^`操作，=1，说明没出现，=0说明重复

### 代码

```cpp
class Solution {
public:
    bool isUnique(string astr) {
        long long a = 0, b = 0, one = 1;
        for(auto& ch : astr)
        {
            if(ch < 64)
            {
                if((a&(one<<ch)^(one<<ch))!=0)
                    a ^= (one<<ch);
                else
                    return false;
            }
            else
            {
                if((b&(one<<(ch-64))^(one<<(ch-64)))!=0)
                    b ^= (one<<(ch-64));
                else
                    return false;
            }
        }
        return true;
    }
};
```

上面程序的1要定义为`long long`,不然报以下错误。

```cpp
Line 16: Char 25: runtime error: shift exponent 51 is too large 
for 32-bit type 'int' (solution.cpp)
```
位移数超过32位int

[https://michael.blog.csdn.net/article/details/104307262](https://michael.blog.csdn.net/article/details/104307262)