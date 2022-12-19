class Solution {
    public int fib(int n) {
        if(n<=0){
            return 0;
        }
        int first = 1;
        int secord = 1;
        int res =1;
        for(int i=3;i<=n;i++){
            res = (first+secord)%1000000007;
            first = secord;
            secord = res;
        }
        return res%1000000007;
    }
}