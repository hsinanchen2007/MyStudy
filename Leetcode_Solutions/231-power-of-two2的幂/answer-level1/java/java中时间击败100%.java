### 解题思路
回顾我们十进制转二进制的算法，
```
// 比如7转成二进制
7/2=3.....1
3/2=1.....1
1/2=0.....1
// 则7的二进制为111

// 比如8转成二进制
8/2=4.....0
4/2=2.....0
2/2=1.....0
1/2=0.....1
// 则8的二进制为1000
```
我们可以观察到，对于非2的幂次数，它的非最左边一位一定会有出现1的；
所以我们在循环对2模、除的时候，如果在最后一次模、除之前余数出现了1，就返回false，否则，如果遍历完，则返回true

### 代码

```java
class Solution {
    public boolean isPowerOfTwo(int n) {
        if(n<=0) return false;
        if(n==1) return true;

        // 直接在最后一次模、除之前结束循环
        while(n>1){
            int c=n%2;
            if(c==1) return false;
            n/=2;

        }
        return true;
    }

    // // 借助位运算的思想，速度不够快
    // public boolean isPowerOfTwo(int n) {
    //     return n>0&&(n&-n)==n;
    // }
}
```