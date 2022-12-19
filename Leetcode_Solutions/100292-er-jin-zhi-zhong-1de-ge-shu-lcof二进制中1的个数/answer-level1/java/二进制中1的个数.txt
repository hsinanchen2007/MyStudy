### 解题思路
此处撰写解题思路

### 代码

```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int count=0;
        while(n!=0)    //若n最高位为1，代表有符号数，条件不能写n>0
        {
           count=count+(n&1);
           n=n>>>1;
        }
        return count;
    }
}
```