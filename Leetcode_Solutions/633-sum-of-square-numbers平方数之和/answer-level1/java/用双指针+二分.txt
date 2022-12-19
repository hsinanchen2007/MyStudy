### 解题思路
一个指针为0，一个为c的sqrt，使i * i+j * j逐渐趋于c

### 代码

```java
class Solution {
    public boolean judgeSquareSum(int c) {
       if(c<0) return false;
       int i=0;
       int j=(int)Math.sqrt(c);
       while(i<=j){//为什么要用等于呢。。。;因为c=2时,j=1,i=1
           int sum=i*i+j*j;
           if(sum>c){
               j--;//i为0，只能缩小j的值来减小sum的值
           }else if(sum<c){
               i++;
           }else if(sum==c){
               return true;
           }
       }
       return false;
    }
}
```