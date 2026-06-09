### 解题思路


### 代码

```java
class Solution {
    public int integerBreak(int n) {
        if(n==2)
        return 1;
        if(n==3)
        return 2;
        int a=n/3;
        int b=n%3;
        if (b == 1){  return 4*(int)Math.pow(3,a-1);}
       else  if(b==2){return  2*(int)Math.pow(3,a);}
       else{ return (int)Math.pow(3,a);}
      
    }
}
```