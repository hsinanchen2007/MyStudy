### 解题思路
此处撰写解题思路
真快
### 代码

```java
class Solution {
    public int multiply(int A, int B) {
        if(B==0)
            return 0;
        return multiply(A,B-1)+A;
    }
}
```