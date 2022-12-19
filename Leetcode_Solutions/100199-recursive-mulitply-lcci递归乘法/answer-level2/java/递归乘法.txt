### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int multiply(int A, int B) {
          if(A==0||B==0) return 0;
       if(A==1||B==1) return A==1?B:A;
       
        return A + multiply(A, B - 1);
    }
}
```