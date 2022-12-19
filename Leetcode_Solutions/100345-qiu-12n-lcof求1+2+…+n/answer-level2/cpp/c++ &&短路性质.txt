### 解题思路
奇淫巧技啊，学到了。
这里可以使用&&符号来使递归可以顺利的进行下去。
A && B = if(A) then B;
所以，我们的判定就是当n = 0的时候，就不行了。所以，就可以从 0 累加上去，得到res的值了。

### 代码

```cpp
class Solution {
public:
    //奇淫巧技啊
    int sumNums(int n) {
        int res = n;
        bool b = (n>0) && (res += sumNums(n-1));
        return res;
    }
};
```