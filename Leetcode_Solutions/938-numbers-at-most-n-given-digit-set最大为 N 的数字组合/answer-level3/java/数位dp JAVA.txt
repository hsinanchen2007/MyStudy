### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    int[] d; // 保存int型的D
    int[] a; // 保存N的所有数位，作为各个数位取值的upper(上界)
    int[] dp; // 记录长度为0到pos位的数字有多少个合法数字
    public int atMostNGivenDigitSet(String[] D, int N) {
        // 数位DP
        // 范围：0~N.
        // 限制条件，只能是 D里面的数字。
        d = new int[10];
        for( int i=0; i<D.length; i++ ) d[Integer.valueOf(D[i])]=1;
        return slover(N);
    }
    int slover( int num ){
        a = new int[11]; // N最多十位
        dp = new int[11];
        for( int i=0; i<dp.length; i++ ) dp[i]=-1;
        int len=0;
        while( num>0 ){
            a[++len] = num%10;
            num = num/10;
        }
        return dfs(len,true,true);
    }
    /**
        pos：当前正在算哪一位pos（ps：高位->低位的顺序）
        limit : 当前pos位是否有upper限制。
        lead : pos及之前位全部为0
    */
    int dfs( int pos, boolean limit,boolean lead ){
        if( pos==0 ) return lead ? 0 : 1;
        if( !limit && !lead && dp[pos]!=-1 ) return dp[pos]; // 无限制、不为0且计算保存过的，直接返回   
        int res=0;
        int upper = limit ? a[pos] : 9;
        for( int i=0; i<=upper; i++ ){
            if( lead && i==0 ) res += dfs( pos-1, limit&&(i==upper),lead&&(i==0) );
            else if(d[i]==1) res += dfs( pos-1, limit&&(i==upper),lead&&(i==0) );
        }
        if( !limit && !lead ) dp[pos] = res;
        return res;
    }
}
```