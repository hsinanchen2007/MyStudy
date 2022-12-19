### 解题思路
思路是将乘法转换成加法
减少运算的方法：让A、B中较小的数表示加法执行的次数，始终让A是A、B中较小的值   if(A>B) swap(A,B);
定义一个全局变量res保存结果。
递归结束条件：A等于0。

![1.png](https://pic.leetcode-cn.com/d2adb1deb2b4669e5a4093e5c9520bbb2aeb933697b4929f53ca72ae2f1e08a5-1.png)


### 代码

```cpp
class Solution {
public:
    int res=0;
    int multiply(int A, int B) {
        if(A>B) swap(A,B);
        if(A==0)    return res;
        res+=B;
        A--;
        multiply(A,B);
        return res;
    }
};
```