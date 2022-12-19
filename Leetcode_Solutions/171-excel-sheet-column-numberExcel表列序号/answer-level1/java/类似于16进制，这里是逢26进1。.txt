class Solution {
    public int titleToNumber(String s) {
        int len = s.length();
        int n = 0, res = 0;
        for(int i = len - 1; i >= 0; i--){
            res += (((int)s.charAt(i)) - 64) * Math.pow(26, n);  //幂为n, 从右往左第n位数就是26的n此方
            n++;
        }
        
        return res;
    }
}