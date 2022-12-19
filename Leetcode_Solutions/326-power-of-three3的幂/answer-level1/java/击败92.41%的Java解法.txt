### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isPowerOfThree(int n) {
      if (n <= 0) {
          return false;
      }  
      while(n % 3 == 0) {
          n /= 3;
      }
      return n == 1;
    }
}
```