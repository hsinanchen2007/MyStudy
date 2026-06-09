其实就是斐波那契数列

递归求解可行但超时。。。。

int climb(int i,int n) {
        if (i > n) {
            return 0;
        }
        if (i == n) {
            return 1;
        }
        return climb(i + 1, n) + climb(i + 2, n);
    }

int climbStairs(int n){
    int count = 0;
    count = climb(0,n);
    return count;
}