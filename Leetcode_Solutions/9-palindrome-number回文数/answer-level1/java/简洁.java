### 解题思路
一开始考虑的是将数字转换为字符串，再将字符串反转、转换为整型，但是这样要使用额外的空间，且会出现溢出。
所以判断数字是否小于0，如果小于0，则返回false，将数字本身进行反转，如果反转后的数字等于数字本身，则返回true

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