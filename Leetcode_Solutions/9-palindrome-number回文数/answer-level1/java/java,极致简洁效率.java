### 解题思路
![QQ截图20200331180942.png](https://pic.leetcode-cn.com/e3ab7dd64a70fef22b85269266579489ebdac6b143071c7e125a053ef9e7a828-QQ%E6%88%AA%E5%9B%BE20200331180942.png)
1.应用了回文数的思路，先计算出这个数的逆置，再与其进行比较。用for写法可以再短一行，不过牺牲了效率，没有必要
### 代码

```java
class Solution {
 public boolean isPalindrome(int x){
     if(x<0) return false ;
       int t = x , res = 0 ;
       while(x!=0){
           res = res*10+x%10;
           x/=10;
       }
       return res==t ;
    }
}
```