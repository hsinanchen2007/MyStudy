思路：
1.首先用一个二维数组保存字符串包含的所有的回文串（如："aab",开一个bool F[3][3]的数组，F[1][2]表示string[1]
到string[2]是否是回文串 ）；
2.要知道S[0,i-1]能划分成多少个回文串，就要知道S[0,j]（j>=0&&j<i,dp[j]就是0~j分成最少回文串）能划分成多少回文串（S[0,j]必然是最少回文串），所以只要b判断S[j,i-1]是不是回文串即可,若是回文串,则dp[i]=dp[j]+1,从0一直往i-1遍历，直到找到最少次数，这样，子问题都是最优解，总问题也就是最优解。
tips:这里讲的是前i个字符，也就是i-1
找出所有回文串：
![palindrome.png](https://pic.leetcode-cn.com/3a16b7f674381525ebac7af1c0dfb1c895607ade8ba6cd78a79b2ee9e58d1a1a-palindrome.png)

动态规划:
![dp.png](https://pic.leetcode-cn.com/6555ff676494398be7528768e17a24383ed18d3b058bed9fe02939ffb4ef40a4-dp.png)

状态转移方程：dp[i]=min(j=0,1,2...i-1){dp[j]+1|s[j,i-1]是回文串}
```
代码块

class Solution {
    public int minCut(String s) {
        char[] ss=s.toCharArray();
        int num=ss.length;
        
        boolean[][] ispalidrome=new boolean[num][num];
        
        for(int i=0;i<num;++i){
            for(int j=0;j<num;++j){
                ispalidrome[i][j]=false;
            }
        }
        
        int n,m,t;
        for(t=0;t<num;++t){
            n=m=t;
            while(n>=0&&m<num&&ss[n]==ss[m]){
                ispalidrome[n][m]=true;
                --n;++m;
            }
            n=t-1;
            m=t;
            while(n>=0&&m<num&&ss[n]==ss[m]){
                ispalidrome[n][m]=true;
                --n;++m;
            }
        }
        int[] F=new int[num+1];
        F[0]=0;
        for(int i=1;i<=num;++i){
            F[i]=i;
            for(int j=0;j<i;++j){
                if(ispalidrome[j][i-1]){
                    F[i]=Math.min(F[j]+1,F[i]);
                }
            }
        }
        
        return F[num]-1;
    }
}
```
