### 解题思路
很简单，利用公式

### 代码

```java
class Solution {
    public int sumNums(int n) {
         return (n+(int) Math.pow(n,2))>>1;
    }
}
```