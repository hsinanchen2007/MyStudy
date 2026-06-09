首先对于负数，由于有个负号，无论如何也不会是回文整数，所以第一种情况对于负数直接返回false。
然后对于正整数，那就简单倒置过来，最后比较原数与倒置后的数即可。

class Solution {
    public boolean isPalindrome(int x) {
        if(x<0)return false;
        
        int ans=0,fx=x;
        while(fx>0)
        {
            int temp=fx%10;
            fx/=10;
            ans=ans*10+temp;
        }
        
        return ans==x?true:false;
    }
}