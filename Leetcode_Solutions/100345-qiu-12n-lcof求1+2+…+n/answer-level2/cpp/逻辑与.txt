### 解题思路
不能使用循环，首先想到的是（1+n）*（中间值）。
中间值因为n为偶数或者奇数需要分别处理，不能使用if关键字。所以使用与操作和0x1比较。

### 代码

```cpp
class Solution {
public:
    int sumNums(int n) {
        int add_one = ((n%2)&0x1);
        
        return (1+n)*(n/2) + add_one*(1+n/2);
    }
};
```