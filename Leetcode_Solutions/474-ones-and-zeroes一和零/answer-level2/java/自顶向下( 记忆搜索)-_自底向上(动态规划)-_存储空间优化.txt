1. ### 说明
    首先这是一个复杂一点的背包问题，m个0，n个1 可以看作是背包，而字符串数组strs是物品列表

    则对于每一个物品(str)，都有放进背包(背包的容量要变成```m-numsOfStr0,n-numsOfStr1```)和不放进背包两种选择,其中```numsOfStr0```表示str中0的个数，```numsOfStr1```表示str中1的个数

    则有
    - 状态: ```f(i,j,k)代表用j个0，k个1组装strs[0...i]的最大个数```
    - 动态转移方程: ```f(i,j,k) = max(f(i-1,j,k),f(i-1,j-numsOfStr0,k-numsOfStr1)) ```

2. ### 先用递归还原动态转移方程

    - #### 代码
    ```
    class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        if(strs.length == 0 || (m==0 && n==0)){
            return 0;
        }
        return tryFindMaxForm(strs,strs.length-1,m,n);
    }
    
    // 用m，n 拼出 strs[0,i] 的 最大个数
    public int tryFindMaxForm(String[] strs,int i,int m, int n){
        if(i<0){
            return 0;
        }
        int numsOf0 = 0;
        int numsOf1 = 0;
        String str = strs[i];
        for(int j = 0;j<str.length();j++){
            if(str.charAt(j) == '0'){
                numsOf0++;
            }else{
                numsOf1++;
            }
        }
        if(m>=numsOf0&&n>=numsOf1){
            return Math.max(tryFindMaxForm(strs,i-1,m,n),
                            1+tryFindMaxForm(strs,i-1,m-numsOf0,n-numsOf1));
        }else{
            return tryFindMaxForm(strs,i-1,m,n);
        }
    }
    ```
    - #### 执行结果，执行时长超时
        ![image.png](https://pic.leetcode-cn.com/8d22c817544343c6cb21d1f1cbc0f21654f3fa18ba3e23f19316c856105ac0b9-image.png)

3. ### 自顶向下-记忆化搜索
    在递归过程中会遇到重叠子问题 如 
    ```
    f(8,5,4) = max(f(7,5,4),f(7,3,2)) str = 1100
    f(8,5,2) = max(f(7,5,2),f(7,3,2)) str = 11
    f(7,3,2) 会被重复计算
    ```
    所以可添加记忆化搜索
    - #### 代码
    ```
    class Solution {
    
    private int[][][] memo;
    public int findMaxForm(String[] strs, int m, int n) {
        if(strs.length == 0 || (m==0 && n==0)){
            return 0;
        }
        this.memo = new int[strs.length][m+1][n+1];
        for(int i = 0;i<memo.length;i++){
            for(int j=0;j<memo[i].length;j++){
                Arrays.fill(memo[i][j],-1);
            }
        }
        return tryFindMaxForm(strs,strs.length-1,m,n);
    }
    
    // 用m，n 拼出 strs[0,i] 的 最大个数
    public int tryFindMaxForm(String[] strs,int i,int m, int n){
        if(i<0){
            return 0;
        }
        if(memo[i][m][n] != -1){
            return memo[i][m][n];
        }
        int numsOf0 = 0;
        int numsOf1 = 0;
        String str = strs[i];
        for(int j = 0;j<str.length();j++){
            if(str.charAt(j) == '0'){
                numsOf0++;
            }else{
                numsOf1++;
            }
        }
        if(m>=numsOf0&&n>=numsOf1){
            memo[i][m][n] = Math.max(tryFindMaxForm(strs,i-1,m,n),
                                    1+tryFindMaxForm(strs,i-1,m-numsOf0,n-numsOf1));
        }else{
            memo[i][m][n] = tryFindMaxForm(strs,i-1,m,n);
        }
        return memo[i][m][n];
    }
       
    }
    ```
    - #### 结果
        
    ![image.png](https://pic.leetcode-cn.com/c1de259e9d2c067facb054590bf0f3618a98bd0a4fe931cf8f64e8048f5407cd-image.png)
    虽然执行成功，但是时间很长和空间占用很打，分析其原因有二
    1. 递归方法栈过长导致执行时长增加
    2. 三维数组在索引上的耗时和空间上的占用
    
4. ### 非递归的动态规划
    为了解决3中的问题1，可以使用自底向上的动态规划，用循环替代递归
    - #### 代码
    ```
    class Solution {
    
    public int findMaxForm(String[] strs, int m, int n) {
        if(strs.length == 0 || (m==0 && n==0)){
            return 0;
        }
        // dp[i][j][k] 表示j个0，k个1组成s[0...i]的最大个数，默认0
        int[][][] dp = new int[strs.length][m+1][n+1];
        
        for(int i=0;i<strs.length;i++){
            int numsOf0 = 0;
            int numsOf1 = 0;
            String str = strs[i];
            for(int j = 0;j<str.length();j++){
                if(str.charAt(j) == '0'){
                    numsOf0++;
                }else{
                    numsOf1++;
                }
            }
            for(int j=m;j>=0;j--){
                for(int k=n;k>=0;k--){
                    if(j>=numsOf0 && k >= numsOf1){
                        if(i==0){
                            dp[i][j][k] = 1;
                        }else{
                            dp[i][j][k] = Math.max(dp[i-1][j][k],1+dp[i-1][j-numsOf0][k-numsOf1]);
                        }
                    }else{
                        dp[i][j][k] = i>0 ? dp[i-1][j][k] : 0;
                    }   
                }
            }
        }
        return dp[strs.length-1][m][n];
    }
    }
    ```
    - #### 结果
        
![image.png](https://pic.leetcode-cn.com/0e1afeb0a9b6f0bd4d8f66b4f211c4911b623a1ad6c3c26292707f202b35040f-image.png)
    执行时长有所下降，但是仍然很高，而且空间占用依旧很大，说明3中的问题2是一个比较严重的问题，我们还没有解决

5. ### 动态规划的空间优化
    观察动态转移方程，我们发现dp[i][][] 只和dp[i-1][][] 有关，所以可以去掉第一维，只用一个二维数组保存上一次计算的结果
    - #### 代码
    ```
    class Solution {
    
    public int findMaxForm(String[] strs, int m, int n) {
        if(strs.length == 0 || (m==0 && n==0)){
            return 0;
        }
        
        int[][] dp = new int[m+1][n+1];
       
        for(int i=0;i<strs.length;i++){
            int numsOf0 = 0;
            int numsOf1 = 0;
            String str = strs[i];
            for(int j = 0;j<str.length();j++){
                if(str.charAt(j) == '0'){
                    numsOf0++;
                }else{
                    numsOf1++;
                }
            }
            for(int j=m;j>=numsOf0;j--){
                for(int k=n;k>=numsOf1;k--){
                    dp[j][k] = Math.max(dp[j][k],1+dp[j-numsOf0][k-numsOf1]);
                }
            }
        }
        return dp[m][n];
    }
    }
    ```
    - #### 结果 
        
![image.png](https://pic.leetcode-cn.com/7dac14bd23ec011b7b6f069b53c3d4502b619444a373f483fcbdfa704bdbdfd3-image.png)

    经过最后一步优化，时间和空间性能都大幅提升
    


