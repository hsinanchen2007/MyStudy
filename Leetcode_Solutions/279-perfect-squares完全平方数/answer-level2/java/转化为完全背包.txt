背包容量为n, 共有sqrtFloor(n)件商品，每件商品体积为其数值的平方，i.e., 当n=10， 有3件商品分别为 (1,2,3)， 体积分别为(1,4,9)。
可多次取商品，找到装满背包时所需商品数量的最小值。 

```
    public int numSquares(int n) {
        int m = sqrtFloor(n);   
     
        int dp [] =  new int [n+1];        
        Arrays.fill(dp, Integer.MAX_VALUE);        
        dp[0] = 0;  // 当i为完全平方数时，让dp[i] = 1

        int temp;         

        for (int j=1; j<=m; j++){
            temp = j*j;
            for (int i=temp; i<=n; i++){
                dp[i] = Math.min(dp[i], dp[i-temp] + 1);
            }
        }        

        return dp[n];        
    }
    
    private int sqrtFloor(int n){
        int floor = 1;

        while(n > floor * floor){
            floor += 1;
        }
        
        return floor;
    }
```
