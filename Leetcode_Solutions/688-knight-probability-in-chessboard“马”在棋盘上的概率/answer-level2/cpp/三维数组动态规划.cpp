### 解题思路
此处撰写解题思路
dp[i][j][k] 表示从坐标（j,i)移动k-1次在棋盘的概率，初始化各个k=0即计算跳一次还在棋盘的概率之后循环。起初需要判断特定值，看代码就行了。
### 代码

```cpp
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        
        if(r<0||c<0||r>=N||c>=N||K<0) return 0;
        if(K==0) return 1;
        if(N<3) return 0;
        vector<vector<vector<double>>> dp(N,vector<vector<double>>(N,vector<double>(K,0)));

        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++){
                int sum=0;
                if(i-1>=0&&j-2>=0) sum++;
                if(i+1<N&&j-2>=0) sum++;
                if(i-2>=0&&j-1>=0) sum++;
                if(i+2<N&&j-1>=0) sum++;
                if(i-1>=0&&j+2<N) sum++;
                if(i+1<N&&j+2<N) sum++;
                if(i-2>=0&&j+1<N) sum++;
                if(i+2<N&&j+1<N) sum++;
                dp[i][j][0]=double(sum)/8;
            }
        for(int k=1;k<K;k++)    
            for(int i=0;i<N;i++)
                for(int j=0;j<N;j++){
                if(i-1>=0&&j-2>=0) dp[i][j][k]+=dp[i-1][j-2][k-1];
                if(i+1<N&&j-2>=0) dp[i][j][k]+=dp[i+1][j-2][k-1];
                if(i-2>=0&&j-1>=0) dp[i][j][k]+=dp[i-2][j-1][k-1];
                if(i+2<N&&j-1>=0) dp[i][j][k]+=dp[i+2][j-1][k-1];
                if(i-1>=0&&j+2<N) dp[i][j][k]+=dp[i-1][j+2][k-1];
                if(i+1<N&&j+2<N) dp[i][j][k]+=dp[i+1][j+2][k-1];
                if(i-2>=0&&j+1<N) dp[i][j][k]+=dp[i-2][j+1][k-1];
                if(i+2<N&&j+1<N) dp[i][j][k]+=dp[i+2][j+1][k-1];
                dp[i][j][k]/=8;
                }
        return dp[c][r][K-1];
    }
};
```