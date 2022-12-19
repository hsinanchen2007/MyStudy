### 解题思路
通过将A与B异或后，得到的结果中1的个数就是返回值。
这里要注意负数的比较，在这里先将输入值A，B转换为无符号数，再进行比较。

### 代码

```cpp
class Solution {
public:
    int convertInteger(int A, int B) {
        unsigned int a=A,b=B;
        int count=0;
        while(a!=0||b!=0)
        {
            count+=(a&1)^(b&1);
            a>>=1;
            b>>=1;
        }
        return count;
    }
};
```