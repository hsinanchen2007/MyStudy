### 解题思路
此处撰写解题思路,首先该程序不能使用乘法，那么我第一个想到的就是加法，而且递归是有次数的，大概在1000次左右，这就要比较A和B哪个大些了，一边加一次，次数就减一次

### 代码

```java
class Solution {
    public int multiply(int A, int B) {
        if(A < 1000){
            if(A == 1)
                return B;
            return multiply(--A, B)+B;
        }else{
            if(B == 1)
                return A;
            return multiply(A, --B)+A;
        }
    }
}
```