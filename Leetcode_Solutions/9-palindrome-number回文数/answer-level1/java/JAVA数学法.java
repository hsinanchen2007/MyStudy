### 解题思路
和第7题整数反转的思路是一样的
利用数学方式计算出数字的相反数如果和原数相等就返回true
### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int r =0;
        int tmp=x;
        while(tmp>0){
            int d =tmp%10;
            r = 10*r+d;
            tmp=tmp/10;
        }
        if(r == x){
            return true;
        }
        return false;
    }
}
```