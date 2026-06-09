先补充背景知识：
1)**集合的状态表示** 
数学上的集合概念要求集合中每一个元素各不相同，例如{1, 4, 5}是一个集合，而{1，4, 4}不是一个集合。对于一个含有n个元素的集合{1,2,3,4,5,6...n}，我们依次枚举每一个值选还是不选，可以枚举出2^(n-1)个子集。当n=4的时候，例如{1，3，4}是一个子集，可以用二进制串来表示，1101，对应到十进制数为13。所以对于一个**集合的子集**，可以用**一个二制数**来表示，进行**压缩存储，节约空间**。这么做还有一个好处是，可以利用二进制的计算操作，来降低循环枚举带来的时间损耗。
2）**二进制操作** 
二进制操作，分为以下几种：
  {&} 与运算 {:} 或运算 {~} 取反 {^} 异或 {>>} 右移 {<<} 左移
  {if(A&(1<<j))} 判断j是否存在
  {A|=(1<<j)}    将j加入A中
  {A-=(1<<j)}    将j从A中抹去
  {A&(-A)}       返回A的lowbit，例如110100返回100；111110000返回10000
  有n个元素，把所有的子集状态枚举一遍，可以这么做：
  {for(int i=0; i<(1<<n); i++)}
3)题目讲解：
  状态的定义：{dp[i][j]}表示已经枚举完前i行，其中第i行的选座情况二进制表示为j的情况下，最多坐下多少人。
  状态的初始化：{dp[0][0]=0, 其他的所有状态先置为-1，表示不可达}
  状态转移：{dp[i][S]=max(dp[i-1][K]+count(S)} 其中S为当前行的选座情况，显然S要是可以取到的，不能含有坏座位；K表示i-1行的选座情况，显然dp[i-1][K]一定是可达的，不可达的没必要进行状态转移；其次S,K不能冲突，具体的冲突判断见代码。
 完成的代码：
```
int dp[10][1<<8];
class Solution {
public:
    
    int lowbit(int x){
        return x&(-x);
    }

    int bcount(int x){
        int cnt = 0;
        while(lowbit(x)&x){
            cnt ++;
            x ^= lowbit(x);
        }
        return cnt;
    }

    int maxStudents(vector<vector<char>>& seats) {
        
        int n = seats.size(); int m = seats[0].size();
        int lim = (1<<m)-1; //二进制状态的上界
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        for(int i=1; i<=n; i++){ //按行进行状态转移
            for(int pre = 0; pre<=lim; pre++){
                if(dp[i-1][pre]==-1) continue;
                for(int cur = 0; cur<=lim; cur++){
                    int flag = true;
                    for(int j=0; j<m; j++){
                        if (!((1<<j)&cur)) continue;
                        if (seats[i-1][j] == '#') flag = false;
                        if (j>=1 && ((cur<<1)&(1<<j))) flag = false;
                        if (j<=m-2 && (cur>>1)&(1<<j)) flag = false;
                        if (j>=1 && ((pre<<1)&(1<<j))) flag = false;
                        if (j<=m-2 && (pre>>1)&(1<<j)) flag = false;
                    }
                    if (flag == true) dp[i][cur] = max(dp[i][cur], dp[i-1][pre] + bcount(cur));
                }
                
            }

        }
        int ans = 0;
        for(int s= 0; s<=lim; s++) ans = max(ans, dp[n][s]);
        return ans;
    }
};
```
