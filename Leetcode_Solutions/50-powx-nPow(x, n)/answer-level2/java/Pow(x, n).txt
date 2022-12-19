二分
```
    public double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n < 0){
            x = 1/x;
        }
        double ans = solve(x, Math.abs(n + 0L));
        
        return ans;
    }
    
    private double solve(double x, long n){
        if(n == 1)
            return x;
        double ans = solve(x, n/2);
        if(n % 2 == 1) 
            return ans *= (ans*x);
        return ans * ans;
    }
    
```
