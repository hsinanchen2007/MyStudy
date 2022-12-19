//斐波那契数列通项公式
class Solution {
    public int fib(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        double d = Math.sqrt(5.0);
        double sn = (1/d)*(Math.pow((1+d)/2, (double) n)-Math.pow((1-d)/2, (double) n));
        return (int) sn;
    }
}