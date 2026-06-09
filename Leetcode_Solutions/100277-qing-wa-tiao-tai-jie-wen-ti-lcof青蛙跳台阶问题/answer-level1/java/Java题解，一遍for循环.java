class Solution {
    public int numWays(int n) {
        int first = 1;
        int secord = 2;
        if(n == 1) return first;
        if(n == 2) return secord;
        int res = 1;
        for(int i=3;i<=n;i++){
            res = (first + secord)%1000000007;
            first = secord;
            secord = res; 
        }
        return res%1000000007;
    }
}