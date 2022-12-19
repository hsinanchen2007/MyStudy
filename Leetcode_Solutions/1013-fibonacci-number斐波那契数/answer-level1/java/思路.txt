### 解题思路
此处撰写解题思路
我的思路:
    先将前面两个数判断1或者是2都是返回1的
    当第三个开始的时候，那么就将前面两个相加，再把第二个赋值给第一个，再把相加的和赋值给第二个，
    重复循环又是一次前面和后面的累加！
最后返回和就行了!ok;
### 代码

```java
class Solution {
    public int fib(int N) {
        int f1=1;
        int f2=1;
        int sum=0;
        if(N==1 || N==2){
            return 1;
        }
        for(int i=3;i<=N;i++){
            sum=f1+f2;
            f1=f2;
            f2=sum;
            
        }
        return sum;
    }
}
```