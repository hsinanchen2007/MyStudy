### 解题思路
此处撰写解题思路
借用第7题解法，先反转 在判断是否相等。
### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        int value  =x;
        if(x < 0){
            return false;
        }
        int rev = 0;
        while(x != 0){
            int newRev = rev*10 + (x%10);
            rev = newRev;
            x = x/10;
        }
        if(rev == value)
        {return true;}
        else{
             return false;
        }
       
    }
}
```