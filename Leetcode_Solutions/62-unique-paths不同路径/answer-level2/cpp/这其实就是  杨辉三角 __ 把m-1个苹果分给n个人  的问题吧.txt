```
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 || n==1) return 1;
        int nums[m][n];
        for(int i=0; i<n; i++){
            nums[0][i] = 1;
        }
        for(int i=0; i<m; i++){
            nums[i][0] = 1;
        }
        
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++){
                nums[i][j] = nums[i][j-1] + nums[i-1][j];
            }
        return nums[m-1][n-1];
    }
};
```
想法一：如图所示，因为robot只能往右和向下，所以第一排和第一列都是1，其它的格子的数字=相邻的左格子+相邻的上格子。代码如上所示，除了循环有更好的办法吗？
![1.png](https://pic.leetcode-cn.com/a2cf2ae5b0bab1665f5f5118def98d326f728dc45f29b40c636b93eca1a227e1-1.png)


//====\\

想法二：M x N 的大小，有m行n列，robot能且只能向下m-1次；因为有n列，所以这m-1次下降有n中选择，所以问题可以变成排列组合问题：
==》  把m-1个苹果放一排，用n-1个挡板去分苹果（可以是0个），总共有多少种分法。


