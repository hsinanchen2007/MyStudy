参考[这篇](https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--41/)中的解法3，自己从底层实现。
首先思考，两个无符号的二进制数，判断他们大小的过程应该是什么样的？应该是从最高位开始，逐个比较，如果相等，继续比较下一位，如果不等（当前位一个为0，一个为1），那当前位为1的那个数大。所以对于[m,n]，如果m等于n，那直接返回m，没什么好说的。如果m<n，那一定是以下的形式。
```
m:  S S S 0 X X X X
n:  S S S 1 X X X X
```
上面的S代表相等，X代表未知（不一定相等）。那数字范围按位与的结果，应该为：
```
S S S 0 0 0 0 0
```
S S S 部分，我们可以通过将m与n进行异或操作得到res，那上面的S都会变为0（因为所有S都是相等的），然后我们从res的最高位开始，统计0的个数count，统计后，对m首先右移（将不是S的部分的后面的位先去掉）再左移（将不是S的部分的后面的位全部补0）。如上面，m与n进行异或操年后结果res为
```
S S S 1 X X X X
```
将res先右移（正数所以左边补0）：
```
0 0 0 0 0 S S S
```
然后将右移结果左移得到：
```
S S S 0 0 0 0 0
```
代码如下：
```java
public int rangeBitwiseAnd(int m, int n) {
        if(m==n)
            return m;
        int res=m^n;//首先进行异或操作
        int count=0;
        //从最高位开始，统计0的个数
        for (int i=31;i>=0;--i){
            if (res>>i==1)
                break;
            else
                count++;
        }
        count=31-count;
        return (m>>count)<<count;
    }
```
上面一定要首先进行m与n是否相等的判断。