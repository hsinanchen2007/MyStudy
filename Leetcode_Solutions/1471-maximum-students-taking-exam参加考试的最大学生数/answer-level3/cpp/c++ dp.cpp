### 解题思路
参照这位大佬的解法 https://leetcode-cn.com/problems/maximum-students-taking-exam/solution/jian-ji-qing-xi-de-zhuang-tai-dp-by-newbie-19/

写一下自己的理解：
1、每一行其实是只依赖于上一行的状态的。所以这里可以用滚动数组优化下空间复杂度。
2、每一行有n个座位，然后要么做人，要么不坐，这样就有2^n种状态，也就是 1<<n。所以建立一个长度为 1<<n 的数组来表示这些状态，留意一点，这里的状态值是不能取到1<<n的，这里蕴含了一个条件，这个状态的数刚好是可以用n位的0或1表示的。如果状态的某一位为1，认为坐了人；为0则认为没坐人。
3、说一下ok这个方法，这个方法就是通过判断是否有相邻的位置都坐了人。用位运算一位一位去遍历。canSit其实差不多，无非是换了坐人的时候，椅子要是ok的。
4、number这个方法就是看状态p里面有几位是1，统计1的个数。
5、当计算非0行的时候，它的状态受到上一行的影响，我们可以用或运算将这行的状态和上一行的状态合并，然后计算是否ok。
6、 dp方程 dp[i][j] = max(dp[i][j], dp[i-1][k] + num);  其中num是第i行j状态下可以坐的人数。 k代表的是上一行的状态。需要遍历上一行的所有状态。

### 代码

```cpp
class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = (int)seats.size();
        if (m == 0) {
            return 0;
        }
        int n = (int)seats[0].size();
        if (n == 0) {
            return 0;
        }
        vector<vector<int>> dp = vector<vector<int>>(2, vector<int>(1<<n)); //使用滚动数组压缩空间
        int res = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<1<<n; j++) {
                if (!canSit(seats, j, i) || !ok(j)) { //先判断这个状态j是否合法
                    continue;
                }
                int num = number(j); //这种状态下坐的人数
                if (i == 0) {
                    dp[i%2][j] = num;
                } else {
                    for (int k=0; k<1<<n; k++) { //这里需要去遍历上一行中的所有可能性
                        if (ok(j|k)) dp[i%2][j] = max(dp[i%2][j], dp[(i+1)%2][k] + num);
                    }
                }
                res = max(res, dp[i%2][j]);
            }
            dp[(i+1)%2] = vector<int>(1<<n);
        }
        return res;
    }
    
    bool ok(int p) {
        int pre = 0;
        while (p != 0) {
            int a = p&0x01;
            if(a==1&&pre==1)return false;
            pre = a;
            p = p >> 1;
        }
        return true;
    }
    
    bool canSit(vector<vector<char>>& seats, int p, int row) {
        int i=0;
        while (p != 0) {
            int a = p&0x01;
            if(a==1 && seats[row][i]=='#') return false;
            i++;
            p = p >> 1;
        }
        return true;
    }
    
    int number(int p) {
        int count=0;
        while (p != 0) {
            int a = p&0x01;
            if(a==1) count++;
            p = p >> 1;
        }
        return count;
    }
};
```