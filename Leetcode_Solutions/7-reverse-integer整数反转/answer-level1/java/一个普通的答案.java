### 解题思路
借鉴leetcode题解，看了很多题解但是目前还是没有太清楚限制范围的确定，这样通过了就先放着，待思考

### 代码

```java
class Solution {
    public int reverse(int x) {
       int ans = 0,pop=0;
       while(x!=0)//reverse the integer
       {
           pop = x % 10;
           x = x/10;
           if (ans>Integer.MAX_VALUE/10)return 0;
           if (ans<Integer.MIN_VALUE/10)return 0;
           ans=ans*10 + pop;
       } 
       return ans;
    }

}
```