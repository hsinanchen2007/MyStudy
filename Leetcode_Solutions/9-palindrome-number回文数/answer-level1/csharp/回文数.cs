```
public class Solution {
    public bool IsPalindrome(int x) {
        //值小于0，直接判断不是回文数
        if(x < 0){
            return false;
        }
        //思路：对比反转数和原来的数是否相同
        int n = x;
        int m = 0;
        while(n != 0){
            m = m * 10 + n % 10;
            n /= 10;
        }
        return m == x;
    }
}
```