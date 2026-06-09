### 解题思路
一目了然

### 代码

```java
class Solution {
    public int multiply(int A, int B) {
        if(B == 0){
            return 0;
        }
        if(B == 1){
            return A;
        }
        return (A << 1) + multiply(A, B - 2);
    }
}
```

