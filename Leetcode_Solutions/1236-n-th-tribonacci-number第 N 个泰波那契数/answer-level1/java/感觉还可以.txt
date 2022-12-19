### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int tribonacci(int n) {
       int a=0,b=1,c=1;
        int temp=0;
       while (n>0){
           temp=a+b+c;
           a=b;
           b=c;
           c=temp;
           n--;
       }
       return a;
    }
}
```