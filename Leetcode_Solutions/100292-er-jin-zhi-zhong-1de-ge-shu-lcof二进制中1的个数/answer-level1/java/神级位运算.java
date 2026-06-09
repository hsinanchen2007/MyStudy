### 解题思路
**看了这篇文章之后几乎可以解决95%的位运算的题目**
[https://zhuanlan.zhihu.com/p/102277869]()
复制链接到浏览器打开

### 代码

```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int count=0;
        while(n!=0){
            n=n&(n-1);
            count++;
        }
        return count;
    }
}
```