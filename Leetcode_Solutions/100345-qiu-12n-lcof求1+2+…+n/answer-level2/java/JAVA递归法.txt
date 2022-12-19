### 解题思路
定义变量sum，通过递归调用sum += n + sumNums(n-1)

### 代码

```java
class Solution {
    int sum = 0;;
    public int sumNums(int n) {
        if(n < 1) return 0;
        if(n > 0) sum += n + sumNums(n-1);
        return sum;
    }
}
```