执行结果：
通过
显示详情
执行用时 :
0 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
34.4 MB
, 在所有 Java 提交中击败了
56.11%
的用户
```
class Solution {
    public int[][] generateMatrix(int n) {
        int[][] res = new int[n][n];
        if(n==0)return res;
        int middle = (n-1)/2;
        int x=1;
        for(int i=0; i<=middle; i++){
             for(int j=i; j<n-i; j++){
                 res[i][j]=x++;
             }
            // System.out.println("1xx"+x);
             for(int j=i+1; j<n-i; j++){
                 res[j][n-i-1]=x++;
             }
             // System.out.println("2xx"+x);
             for(int j=n-i-2; j>=i; j--){
                 res[n-i-1][j]=x++;
             }
             // System.out.println("3xx"+x);
            for(int j=n-i-2; j>i; j--){
                 res[j][i]=x++;
             }
             // System.out.println("4xx"+x);
        }
        return res;
    }
}
```
