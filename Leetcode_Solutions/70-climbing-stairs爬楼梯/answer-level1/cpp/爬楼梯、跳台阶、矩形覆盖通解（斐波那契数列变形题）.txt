class Solution {
public:
    int climbStairs(int n) {
        if ( n <= 0 )
            return 0;
        if ( n < 3 )
            return n;
        int c1 = 1, c2 = 2, cn;
        //不使用递归fn = f( n-1 ) + f( n-2 )，可能会超时
        for ( int i=3; i<=n; i++ ){
            cn = c1 + c2;
            c1 = c2;
            c2 = cn;
            
        }
        return cn;
        
    }
};