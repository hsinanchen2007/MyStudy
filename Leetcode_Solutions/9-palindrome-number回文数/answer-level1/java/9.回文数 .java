1. 负数肯定不是回文数
2. 正数的话想办法算出它的回文数,然后判断是否与原数字相同即可
3. ```
class Solution {
    public boolean isPalindrome(int x) {
        int res = 0;
        int tmp = x;
        // 负数一定是错的
        if (x<0) {
            return false;
        }        
        else if (x==0) {
            return true;
        }
        else {
            while (x>0) {
                res = x%10 + res*10;
                x/=10;     
            }
        }
        return res==tmp;
    }
}
```
