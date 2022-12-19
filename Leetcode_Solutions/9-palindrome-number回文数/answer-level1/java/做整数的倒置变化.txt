### 解题思路
1 做整数的倒置变化
### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        if(x<0) return false;
        int p =Math.abs(x);
        int a=0;
        while(p>0){
            int b=p%10;
            p=p/10;
            a=a*10+b;
        }
        return a==x;
    }
}
```