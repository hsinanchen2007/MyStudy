
class Solution {
    public int reverse(int x) {
        int rev = 0;
        int pop = 0;
        while(x != 0 ){
            //末尾按照顺序取出(数取余数);
            pop = x % 10;
            //缩小10倍;
            x = x / 10;
            //解决反转之后数越界问题;
            if(rev > Integer.MAX_VALUE/10 || (rev == Integer.MAX_VALUE && x > Integer.MAX_VALUE % 10 ) ) {
                 rev = 0;
                 break;
            }
            if(rev < Integer.MIN_VALUE/10 || (rev == Integer.MIN_VALUE && x < Integer.MIN_VALUE % 10 ) ) { 
                 rev = 0;
                 break;
            }
            rev = rev * 10 + pop;
        }
        return rev;
    }
}