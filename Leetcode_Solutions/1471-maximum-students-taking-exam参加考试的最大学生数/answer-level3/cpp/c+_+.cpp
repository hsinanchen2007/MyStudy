### 解题思路
![image.png](https://pic.leetcode-cn.com/4755277d4505861745f0d398677dffb88a219511e4bf80a7f116e9870cf02fae-image.png)


### 代码

```cpp
class Solution {
public:
    bool st_row[8][1 << 9];
    int dp[8][1 << 9];
    int maxStudents(vector<vector<char>>& seats) {
        int row = seats.size(), col = seats[0].size();
        memset(dp, -0x3f, sizeof dp);
        //预处理所有行可行的情况
        init(seats, row, col);
        cout << st_row[1][0] << endl;
        //初始化第一行
        for(int i = 0;i < 1 << col;++i){
            if(!ok(i) && st_row[0][i]){
                dp[0][i] = count(i);
            }
        }

        int ans = 0;

        for(int i = 1;i < row;++i){
            for(int j = 0;j < 1 << col;++j){//第i - 1行状态 j
                    for(int k = 0;k < 1 << col;++k)//第 i行 状态 k
                        if(st_row[i-1][j] && st_row[i][k] && !ok(j | k)){
                            dp[i][k] = max(dp[i][k], dp[i-1][j] + count(k));
                            ans = max(ans, dp[i][k]);
                        }
            }
        }
        return ans;
    }
    //判断一行里是否有连续的 1
    bool ok(int t){
        return (t & (t << 1)) || (t & (t >> 1));
    }
    //预处理每行 可行的 状态
    void init(vector<vector<char>>& seats, int row, int col){
        for(int i = 0;i < row;++i){
            st_row[i][0] = true;
            for(int j = 0;j < 1 << col;++j){
                int cnt = 0;
                for(int k = 0;k < col;++k)
                    if(j >> k & 1){
                        if(seats[i][k] == '#') {
                            st_row[i][j] = false;
                            break;
                        }
                        ++cnt;
                        if(cnt == 2) {
                            st_row[i][j] = false;
                            break;
                        }
                        st_row[i][j] = true;
                    }
                    else cnt = 0;
            }
        }
    }
    //统计 1 的个数 
    int count(int k){
        int cnt = 0;
        while(k){
            ++cnt;
            k -= k & -k;
        }
        return cnt;
    }
};
```