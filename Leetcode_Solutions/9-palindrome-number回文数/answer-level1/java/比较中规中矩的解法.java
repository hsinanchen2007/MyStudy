### 解题思路
情况1：当x为负数时 回文数必与之不相等 返回false；
情况2：当x为0时 回文数为0 返回true；
情况3：使用while计算得出回文数 判断是否与输入x相等

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        int initx=x;
        int rev=0;

        if(initx<0){
         return false;
        }

       if(initx==0){
         return true;
        }

        while(x!=0){
            int b=x%10;
            x/=10;
            if(rev>Integer.MAX_VALUE){
                return false;
            }
            if(rev<Integer.MIN_VALUE){
                return false;
            }
            rev=rev*10+b;
        }

        if(initx==rev){
            return true;
        }else{
            return false;
        }
    }
}
```