### 解题思路
- 相当于把给定数组分成n个区间，要去每个区间的最大值的和为最小
- 所以第一步要把**每个区间的最大值**也就是最大难度计算出来，用**diff[i][j]**来表示区间**[i,j]**最大工作量
    - 最大工作量为 ：[i, j-1] 和 j 本身的工作量的 较大值
    -  max(diff(i,j-1),j)
- 接下来要把整个任务数组分为 d个区间 f[i][j]表示为前i项目用j天完成最小的工作量 
  也就是把数组的**前 i 个元素** 分为 **j个区间** ，j个区间最大值相加的的 最小的那个值
- 不断维护该值
  - 为 0 1 2 ... k ...i   **[0,k] 分为 j-1个区间**, 其最小值为f[k][j-1] ， 剩余部分为1个区间 [k+1,i] 最大工作量为diff[k+1][i]
  - 二者相加 即为 f[i][j] =  f[k][j-1] + diff[k+1][i];     
### 代码

```cpp
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        int n = jobDifficulty.size();
        const int INF = 100000000;
        
        vector<vector<int>> f (n + 1, vector<int>(d + 1, INF));
        vector<vector<int>> diff(n + 1, vector<int>(n + 1, 0));  // 某个区间起点的任务的最大难度【一天内完成】
                               
        for(int i = 1; i <= n; i++){
            diff[i][i] = jobDifficulty[i - 1];
            for(int j = i + 1; j <= n; j++)
                diff[i][j] = max(diff[i][j - 1], jobDifficulty[j - 1]);  //  以[i,j]区间为任务的最大难度
        }
                              
        f[0][0] = 0;
        
        for(int i = 1; i <= n; i++)   //  待分的总区间
        {
            for(int j = 1; j <= min(d, i); j++ )  // 分成j个小区间
            {
                for(int k = 0; k < i; k++)        // 以 k为结尾的 j-1个小区间  和最后一个以k+1k开头的小区间
                {
                    f[i][j] = min(f[i][j], f[k][j - 1] + diff[k + 1][i]);
                    //cout << f[i][j] << endl;
                }
            }
        }
                
        
        if(f[n][d] == INF)  f[n][d] = -1;
        
        return f[n][d];
              
        
           
                                               

    }
};
```