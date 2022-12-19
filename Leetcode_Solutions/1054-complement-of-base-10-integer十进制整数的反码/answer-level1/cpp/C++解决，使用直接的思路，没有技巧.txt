### 解题思路
直接思路，只有两步。
先得到整数的二进制数。
将二进制数的01翻转，然后直接处理对应2的幂相加。

### 代码

```cpp
class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0)
            return 1;
        vector<int> bin;
        int lenOfInt = 0;
        //用一个vector，得到二进制的数字，顺序是错的，不用管。
        //重要的是记住二进制数字的长度。
        while (N > 0)
        {
            bin.push_back(N%2);
            lenOfInt++;
            N /= 2;
        }
        int rlt = 0;
        //按照二进制数的长度，从最后一个开始处理。
        for (int i=0; i<lenOfInt; i++)
        {
            int last = bin.back();
            if (last == 0)
                rlt += pow(2, lenOfInt-i-1);
            bin.pop_back();
        }
        return rlt;
    }
};
```