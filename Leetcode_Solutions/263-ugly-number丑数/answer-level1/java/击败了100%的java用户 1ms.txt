# [263 . 丑数](https://www.cnblogs.com/hh09cnblogs/p/11604206.html)
```
class Solution {
    public boolean isUgly(int num) {
        if( num == 1 || num == 2  || num == 3 || num == 5 ){
            return true;
        }
        if( num == 0 || (num % 2 != 0 && num % 3 != 0 && num % 5 != 0) ) {
            return false;
        }
        return ( num % 2 == 0 && isUgly(num/2)  )
                || (num % 3 == 0 && isUgly(num / 3))
                || (num % 5 == 0 && isUgly(num / 5));
    }
}
```
