```
/*
stat定义：将本层的所有有学生的位置当做1，没学生的位置当做0之后，进行2->10进制转换得到的整数。(状态压缩)
状态 ：dp[i][j] 为第i层stat为j，时前i层最多可以坐下多少学生。
状态转移：dp[i][j] = max(dp[i-1][k] + cal(j))  (0 <= k < 1 << len)
*/

class Solution {
public:
    int f[8] = {1, 2, 4, 8, 16, 32, 64, 128}; //标志位 用于条件过滤
    int len;    //每一排长度
    int depth;  //总共有多少排
    
    //计算某个数中1的个数
    int cal(int x) {
        int sum = 0;
        while(x) {
            sum += (x % 2);
            x /= 2;
        }
        return sum;
    }
    
    //参数：图   深度   当前的stat  上一排的stat
    bool is_ok(vector<vector<char>>& seats, int deep, int x, int last) {
        for (int i = 0; i < len; i++) {  //对该 stat 以及 上一排的 stat 遍历其二进制位(注意辅助数组f)
            //当前这个点不存在学生，不需要考虑可行性，直接跳过
            if (!(x&f[i])) continue;
            //存在学生，但是这是个坏桌子，所以该 stat 不成立
            if (seats[deep][i] == '#') return false;
            //该位置左右位置存在学生，所以该stat不成立
            if ((i > 0 && (x&f[i-1])) || (i < len-1 && (x&f[i+1]))) return false;
            //该位置的上一行左右位置存在学生所以不成立
            if (last != -1 && ((i > 0 && (last&f[i-1])) || (i < len-1 && (last&f[i+1])))) return false;
        }
        return true;
    }
    
    int maxStudents(vector<vector<char>>& seats) {
        len = seats[0].size();
        depth = seats.size();
        int res = 0;
        int dp[10][300] = {0};
        for (int i = 0; i < depth; i++) {
            for (int j = 0; j < 1 << len; j++) {
                int Max = 0;
                for (int k = 0; k < 1 << len; k++) {
                    if (is_ok(seats, i, j, k)) {
                        if (i == 0) dp[i][j] = max(dp[i][j], cal(j));
                        else dp[i][j] = max(dp[i][j], dp[i-1][k] + cal(j));
                    }
                }
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};
```
题解见注释