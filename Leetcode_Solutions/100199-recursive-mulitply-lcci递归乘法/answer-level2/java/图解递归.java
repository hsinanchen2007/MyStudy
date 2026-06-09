### 解题思路
例如：
　　把4×5拆成5+3×5--->5+5+2×5--->5+5+5+1×5--->5+5+5+5实现递归
图解：
![image.png](https://pic.leetcode-cn.com/4324d6d7604031af36c5dea4ca4903a58076fa4eef06244b02d1762bc914a72c-image.png)


### 代码

```java
class Solution {
    public int multiply(int A, int B) {
        //此处是为了防止溢出
        int temp=A+B;
        A=(int)Math.min(A,B);
        B=temp-A;
        if(A==1){
            return B;
        }
        return B+multiply(A-1,B);
    }
}
```
结语：如有不足，请多指教