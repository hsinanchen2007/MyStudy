public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int r=1;
        int digit;
        for(int i=31;i>=0;i--){
        r=r<<1;
        digit = 1 & n>>(31-i);
        r=r|digit;
        }
        return r;
    }
}