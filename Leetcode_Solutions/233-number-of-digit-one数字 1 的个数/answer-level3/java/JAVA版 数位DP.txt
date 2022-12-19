### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    int[] a;
    int[][] dp; // 保存 [pos][count]的dfs值，即在pos位为1数量为count的时候，总count为多少。

    int countDigitOne(int n) {
       // 数位DP
       if( n==0 )return 0;
       return slover(n);
    }
    int slover( int num ){
        int len=0;
        a = new int[11];
        dp = new int[11][11];
        for( int i=0; i<11; i++){
            for( int j=0; j<11; j++){
                dp[i][j]=-1;
            }
        }
        while( num>0 ){
            a[++len] = num%10;
            num = num/10;
        }
        return dfs(len,0,true); // 最高位开始，count为0，有限制状态
    }
    int dfs( int pos, int count, boolean limit){
            if( pos<=0 ) return count; // 遍历结果，返回当前的count
            if( !limit && dp[pos][count]!=-1 ) return dp[pos][count];
            // 求一下当前位的上界
            int upper = limit ? a[pos]:9;
            int res=0;
            for( int i=0; i<=upper; i++ ){
                res += dfs( pos-1, count+((i==1)?1:0), limit&&(i==upper) );
            }
            if( !limit ) dp[pos][count] = res;
            return res;
        }
}







```