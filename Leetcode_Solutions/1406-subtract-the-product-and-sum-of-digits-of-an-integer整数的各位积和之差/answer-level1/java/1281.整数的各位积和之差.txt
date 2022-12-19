### 解题思路
分别求出各位的积和和，相减返回即可

### 代码

```java
class Solution {
    public int subtractProductAndSum(int n) {
        int a=1,b=0;
       while(n!=0){
           a*=n%10;
           b+=n%10;
           n=n/10;
       }
       int s=0;
       s=a-b;//通过s返回最终结果
       return s;
    }
}
```