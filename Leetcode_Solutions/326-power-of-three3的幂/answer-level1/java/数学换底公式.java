### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isPowerOfThree(int n) {
        if(n==0)
            return false;
        double i = Math.log10(n)/Math.log10(3);
        return i==(int)i;
    }
}
```