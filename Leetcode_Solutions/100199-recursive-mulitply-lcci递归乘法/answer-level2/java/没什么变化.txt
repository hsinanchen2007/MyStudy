![image.png](https://pic.leetcode-cn.com/6e808efe4ac1bb438e4d3f7637f19ef3cd25ed809b09f485b255bd6958a1c5a9-image.png)

```
class Solution {
    public int multiply(int A, int B) {
        //提高速度防止栈溢出，找大小
        int temp = A + B;
        A = (int)Math.min(A,B);
        B = temp - A;
        
        if(A == 1)return B;
        return B + multiply(A - 1,B);
    }
}
```
