解法的大致思路是将***参数反转***，***判断两数是否相等，相等则为回文数，否则不是回文数***。由题目可知，负数带了符号则一定不是回文数，因此直接返回false。之后使用long型变量来接收反转后的结果防止数据溢出，之后对反转后的数据进行校验如果超出了int的范围那么一定不是回文数（超出范围了一定不相等，因此也不是回文数）。如果在int范围内则比较两者是否相等。
```
class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        long ret = 0L;
        int temp = x;
        while(x != 0){
            ret *= 10;
            ret += (x % 10);
            x /= 10;
        }
        if(ret > Integer.MAX_VALUE || ret < Integer.MIN_VALUE){
            return false;
        }else{
            return (int)ret == temp ? true : false;
        }
    }
}
```