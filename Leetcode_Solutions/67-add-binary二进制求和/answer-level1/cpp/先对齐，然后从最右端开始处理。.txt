### 解题思路
一开始直接写了两个函数（二进制转十进制，十进制转二进制），被溢出虐了千万遍。
![捕获.PNG](https://pic.leetcode-cn.com/dfa7d94722dd00c7f7d4fa4de74a67dddc02c8617b0d3c2b6d4f974f36259ffb-%E6%8D%95%E8%8E%B7.PNG)


### 代码

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        int Asize = a.size();
        int Bsize = b.size();
        if (Asize > Bsize)
        {
            string tmp(Asize - Bsize, '0');
            b = tmp + b;
        }
        else if (Bsize > Asize)
        {
            string tmp(Bsize - Asize, '0');
            a = tmp + a;
        }

        int count = 0;  //标志位，是否进1
        for (int i = a.size() - 1; i >= 0; --i)
        {
            int num = a[i] - '0' + b[i] - '0' + count;  //ACSII转int
            a[i] = num % 2 + '0';  //int转ACSII
            count = num / 2;
        }
        //判断最左端是否进1
        if (count == 1)
            a = '1' + a;
        return a;
    }
};
```