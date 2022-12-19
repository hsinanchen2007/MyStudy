### 解题思路
以12321为例
首先判断help除数 ：求5次 12321 / 10 直到 12321 < 10 ;与此同时help=1 * 10 也执行5次 得help=100000；
然后循环判断12321首尾两位是否相等 ：12321 / 10000 得首位 1 ； 12321 % 10 得末位 1 ；
若首尾两位相等 ：去掉首尾两位 12321 / 10000 =2321（去首位）2321 % 10 =232（去末位）；再用232循环上面步骤判断。

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) return false;
        int help = 1;
        int tem = x;
        while (tem >= 10){   //根据x位数 判断除数为多少
            help *= 10;      //x每少一位 help就多一位
            tem /= 10;
        }
        while (x != 0){
            if (x / help != x % 10){   //x的首尾两位是否相等
                return false;
                
            }
            x = x % help / 10;         //去掉x首尾两位
            help /= 100;               //help也相应减少两位
        }
        return true;
        
    }
}
```