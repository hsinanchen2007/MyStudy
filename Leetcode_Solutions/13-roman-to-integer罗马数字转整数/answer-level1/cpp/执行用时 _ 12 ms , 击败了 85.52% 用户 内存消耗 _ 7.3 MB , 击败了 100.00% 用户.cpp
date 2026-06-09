### 解题思路
首先编写解码函数```trans(char s)```，然后从尾部进行逐个扫描。
发现如果左边的字符比右边的字符小，那么需要间去该字符代表的数值。
比如```IX```就是```5-1=4```.其他的同理。
### 代码

```cpp
class Solution {
     int trans(char s)
    {
/*
字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/
        switch (s)
        {
        case 'I':return 1;
        case 'V':return 5;
        case 'X':return 10;
        case 'L':return 50;
        case 'C':return 100;
        case 'D':return 500;
        case 'M':return 1000;
        default:return 0;
        }
    }
public:
    int romanToInt(string s) {
        size_t len = s.size()-1;
        if (len == -1)return 0;
        int sum =trans(s[len]);//return the result.
        while (len>0) {
            if (trans(s[len]) > trans(s[len-1]))//操作判断
            {
                sum -= trans(s[len-1]);
            }
            else sum += trans(s[len-1]);
            len--;
        }
        return sum;
    }
};
```