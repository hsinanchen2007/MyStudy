### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int getSum(int a, int b) {
        return (int)(Math.log((double)Math.pow(2,(a+b)))/Math.log(2));
    }
}
```