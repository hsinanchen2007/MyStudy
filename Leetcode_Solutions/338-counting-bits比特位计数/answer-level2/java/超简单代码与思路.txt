### 解题思路
此处撰写解题思路
一个数的二进制中1的个数一定等于一定等于这个数的最底位的1变为0后的数中1的个数加1；
如2=(10),那么2中1的个数等于（00）中1的个数加1=1；
6=(110),那么6中1的个数等于(100)中1的个数加1；
i&(i-1)可以得到i的最低位变为0后的数；
所以得到表达式ret[i]=ret[i&(i-1)]+1;
是不是很简单。。。
### 代码

```java
class Solution {
    public int[] countBits(int num) {
        int[] ret=new int[num+1];
        for(int i=1;i<=num;i++){
            ret[i]=ret[i&(i-1)]+1;
        }
        return ret;
    }
}
```