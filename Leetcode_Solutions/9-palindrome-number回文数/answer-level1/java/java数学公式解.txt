### 解题思路
最关键的地方主要是数学方法，计算公式
最开始想不到
 while(x!=0){
         ans=ans*10+x%10;
         x=x/10;
     }
这里的操作就写不出来的
### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {

    int ans=0;
     int sum=x;
     if(x<0)
     return false;
     while(x!=0){
         ans=ans*10+x%10;
         x=x/10;
     }
    if(ans==sum)
     return true;
     else 
     return false;

    }
}
```