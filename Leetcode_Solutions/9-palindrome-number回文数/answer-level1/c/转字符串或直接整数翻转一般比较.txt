```
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        s = str(x)
        return s == s[::-1]
```
整数翻转一半比较
```
bool isPalindrome(int x){
    int r = 0;
    int m = 0;
    if(x < 0 || (x %10 == 0 && x > 0))
        return false;
    while(x > r)
    {
        m = x % 10;
        x /= 10;
        if(x == r)
            break;            
        r = r*10 + m;
    }
    return x==r;
}
```
