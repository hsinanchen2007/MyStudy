推论：   
1、只要待取披萨两两不相邻，总有一种取法可以取到。        
2、如果待取披萨存在相邻，则无法取到。
证明：   
1、先不断地取披萨间隔大于1的部分，如 0,0,1,0,0,1,0,0,0,1，0,0……，易知可以取到。
对于剩余间隔为1的部分,找到合适的开头一定可以整理成如下形式，1,0,1,0,1,0,0,0,0,1,0,1,0,0，...只需从左到右依次取1所在位置的披萨即可。       
2、如果披萨相邻，如0,1,1,……，假设左边的1先被取走,此时右边的1如果未被取走的话就会被朋友取走，如果右边的1之前被朋友取走的话就再也无法取走，如果右边的1之前被自己取走的话就和假设相矛盾，所以不可能将两个1都取走。


所以不需要考虑具体是怎么取的，只需找到slices里不相邻的n/3个数和的最大值。
考虑到0 和 n-1也是相邻的，所以本人分了两种情况讨论，一种是去掉第0项算结果，一个是去掉第n-1项算结果。
dp0[i][j]表示第j次取，第i块披萨为结尾的最大值，不包括第0项。
dp1[i][j]表示第j次取，第i块披萨为结尾的最大值，不包括第n-1项。
prev[i][j]表示dp[i][0:j]的最大值。
```
class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n=slices.size();
        vector<vector<int>> dp0(n,vector<int>(n/3,0));
        vector<vector<int>> dp1(n,vector<int>(n/3,0));
        vector<vector<int>> prev0(n,vector<int>(n/3,0));
        vector<vector<int>> prev1(n,vector<int>(n/3,0));
        dp0[0][0]=slices[0];
        dp1[0][0]=slices[0];
        prev0[0][0]=slices[0];
        for(int i=1;i<n;i++){
            dp0[i][0]=slices[i];
            prev0[i][0]=max(dp0[i][0],prev0[i-1][0]);
            dp1[i][0]=slices[i];
            prev1[i][0]=max(dp0[i][0],prev1[i-1][0]);
        }
        for(int k=1;k<n/3;k++){
            for(int i=k*2;i<n-1;i++) {
                dp0[i][k]=max(dp0[i][k],prev0[i-2][k-1]+slices[i]);
                prev0[i][k]=max(prev0[i-1][k],dp0[i][k]);
            }
        }
        for(int k=1;k<n/3;k++){
            for(int i=k*2+1;i<n;i++) {
                dp1[i][k]=max(dp1[i][k],prev1[i-2][k-1]+slices[i]);
                prev1[i][k]=max(prev1[i-1][k],dp1[i][k]);
            }
        }
        return max(prev0[n-2][n/3-1],prev1[n-1][n/3-1]);
    }
};

```
