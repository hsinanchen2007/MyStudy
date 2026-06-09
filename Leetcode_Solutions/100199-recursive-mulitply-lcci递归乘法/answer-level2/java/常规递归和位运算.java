### 解题思路
常规的递归方法,每一层用被乘数+(乘数-1)*被乘数,直到乘数为0时结束递归就可以了,不过要注意当乘数过大时有可能会造成栈溢出
### 代码

```java
class Solution {
    public int multiply(int A, int B) {
        //让乘数始终小于被乘数可以减少递归的层数
        if(A>B)return multiply(B,A);
        if(A==0)return 0;
        return B+multiply(A-1,B);
        /*利用位运算递归
        利用位运算左移相当于乘二右移除二的特性
        if(A==1)return B;
        //A%2==0时A/2和A>>1是等价的只需要不停的递归就可以了
        if(A%2==0)return multiply(A>>1,B<<1);
        //A%2==1时A*B=(A>>1)*(B<<1)+B;要注意的是A和B的值在这里是没有变的
        return multiply(A>>1,B<<1)+B;
        */ 
    }
}
```