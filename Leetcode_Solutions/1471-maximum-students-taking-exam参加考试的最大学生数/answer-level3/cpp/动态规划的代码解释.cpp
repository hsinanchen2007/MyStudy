### 解题思路
把`seats`里好座位用`1`表示,坏座位用`0`表示,那么每行都是一个二进制串,这个二进制串可以用一个对应的数(这里用十进制)来存储
`bitSeats[i]`:
```cpp
 [["#",".","#","#",".","#"],        //0 1 0 0 1 0  -> bitSeats[0] = 18
  [".","#","#","#","#","."],        //1 0 0 0 0 1  -> bitSeats[1] = 33
  ["#",".","#","#",".","#"]]        //0 1 0 0 1 0  -> bitSeats[2] = 18
```
定义：
`m = seats.size()`,行数；`n = seats[0].size()`列数。
那么每行座为的情况都可以用`[0,2^n - 1]`里的一个数来表示。
当`n = 8`,右边为每行座位的情况，左边为十进数
```cpp
0  :  00000000
1  :  00000001
2  :  00000010
3  :  00000011
4  :  00000100
5  :  00000101
6  :  00000110
7  :  00000111
8  :  00001000
9  :  00001001
10  :  00001010
11  :  00001011
12  :  00001100
13  :  00001101
14  :  00001110
15  :  00001111
16  :  00010000
17  :  00010001
18  :  00010010
19  :  00010011
20  :  00010100
21  :  00010101
22  :  00010110
23  :  00010111
......省略若干行
246  :  11110110
247  :  11110111
248  :  11111000
249  :  11111001
250  :  11111010
251  :  11111011
252  :  11111100
253  :  11111101
254  :  11111110
255  :  11111111
```
`cnt1[i]`:存储`i`对应二进制里多少个位为`1`。
dp[i][j]:**表示第`i`行在为`j`对应二进制的那种坐人方法时前`i`行最大坐学生数。**
对于这段代码：
![image.png](https://pic.leetcode-cn.com/cc4b1a67960283617e69fe878f201fe2fb927c3ead8afb030b5cfe96667f152f-image.png)
1. `for(int j = 0; j < (1<<n); j++)`  这个循环遍历 `2^n`次,它要找到一些坐法，满足：
    1). `(j & curRow) == j` 这种坐法是第`i`行好位置的子集，就是位置是这样`1100`,你只能是`1000`,`0100`,`0000`,`1100`(这个违反下一条),不能`1110`这种没好位置也坐。
    2). `!(j & (j >> 1))`,不能出现两个人挨着坐
![image.png](https://pic.leetcode-cn.com/25956a44909c6d020953bb569fd9720a249b873d8d13bd822276d59c4b5c8fdb-image.png)

2.for(int k = 0; k < (1<<n); k++)  这个循环也遍历 `2^n`次,作用是当第`i`(`curRow`)行为`j`对应二进制的那种坐人方法时,在第`i-1`行(`curRow`的上一行)找不和它冲突的一些坐法`k`,来更新`dp[i][j]`,即第`i`行在为`j`对应二进制的那种坐人方法时前`i`行最大坐学生数.
更新的状态转移方程是：`dp[i][j] = max(dp[i][j], dp[i-1][k] + cnt1[j]);`
`k`得满足：
    1. `dp[i - 1][k] != -1`,第`i-1`行`k`坐法合法
    2. `!((j >> 1) & k)`:第`i`行`j`坐法不能有学生坐当第`i-1`行为`k`坐法时的合法学生左上角
    3. `!((j >> 1) & k)`:不能右上角




### 代码

```cpp
class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size(), n = seats[0].size();
        vector<int>bitSeats(m,0);    
        for(int i = 0; i < m; i++)
        {
            int curRow = 0;
            for(int j = 0; j < n; j++)
            {
                curRow = curRow * 2 + (seats[i][j] == '.');
            }
            bitSeats[i] = curRow;
        }
        vector<int>cnt1( 1<<n, 0);
        for(int i = 1; i < (1<<n); i++) 
            cnt1[i] = cnt1[i>>1] + (i&1);//`i`与`i>>1`位为1的个数就相差一(被右移移出的那位为1时) 

        vector<vector<int>>dp(m+1, vector<int>(1<<n, -1));
        dp[0][0] = 0;
        for(int i = 1; i <= m; i++)
        {
            int curRow = bitSeats[i-1];
            for(int j = 0; j < (1<<n); j++)
            {
                if ((j & curRow) == j && !(j & (j >> 1)))
                {
                    for(int k = 0; k < (1<<n); k++)
                    {
                        if (dp[i - 1][k] != -1 && !(j & (k >> 1)) && !((j >> 1) & k))
                        {
                            dp[i][j] = max(dp[i][j], dp[i-1][k] + cnt1[j]);
                        }
                    }
                }
            }
        }
        return *max_element(dp[m].begin(), dp[m].end());
    }
};
```

建议参考这个：
`https://leetcode.com/problems/maximum-students-taking-exam/discuss/503686/A-simple-tutorial-on-this-bitmasking-problem`
