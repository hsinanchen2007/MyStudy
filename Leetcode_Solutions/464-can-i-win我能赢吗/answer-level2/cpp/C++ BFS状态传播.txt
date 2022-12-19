首先假设`maxChoosableInteger`为`N`
那么所有可能的状态就有`1<<N`个
1，先找到最终确定的状态
2，根据确定的状态去逐渐向前传播状态，类似于[猫和老鼠](https://leetcode-cn.com/problems/cat-and-mouse/)那一题的传播方法
3，令`winners[i]`代表状态为`i`时的胜利者，状态传播方式如下：
1）假设当前轮到了`A`来选数字，如果`i`的所有子状态都是`B`赢，那么此状态的赢者是`B`，
2）如果`i`的所有子状态中至少有一个是`A`赢，那么此状态的赢者就是`A`
3）以上两个情况都不满足，那么本轮的赢者不确定为`NONE`
效率不如记忆化DFS来的高，作为BFS解法方法算作一种题解参考
```C++ []
class Solution {
public:
    enum class Winner {NONE, A, B};
    enum class Turn {A, B};
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal == 0) return true;
        int N = maxChoosableInteger;
        if (N * (N + 1) / 2 < desiredTotal) {
            return false;
        }
        int S = 1 << N;
        vector<Winner> winners(S, Winner::NONE);
        vector<Turn> turns(S, Turn::A);
        queue<int> q;
        // 寻找所有能确定赢者的状态，将该状态入队列，为后面广度优先搜索做准备
        for (int i = 0; i < S; ++i) {
            int sum = 0;
            int k = 1;
            int mx = 0;
            for (int j = 0; j < N; ++j) {
                if (i >> j & 1) {
                    sum += j + 1;
                    k ^= 1;
                } else {
                    mx = max(mx, j + 1);
                }
            }
            turns[i] = k == 1 ? Turn::A : Turn::B;
            if (sum < desiredTotal && sum + mx >= desiredTotal) {
                winners[i] = turns[i] == Turn::A ? Winner::A : Winner::B;
                q.push(i);
            }
        }
        // 广度优先搜索去搜索所有队列状态元素的父状态，根据子状态去确定父状态
        while (!q.empty()) {
            int s = q.size();
            int i = q.front();
            q.pop();
            for (int j = 0; j < N; ++j) {
                if ((i >> j & 1) == 0) continue;
                int t = i & ~(1 << j);
                if (winners[t] != Winner::NONE) continue;
                if (turns[t] == Turn::B && winners[i] == Winner::B) {
                    winners[t] = Winner::B;
                } else if (turns[t] == Turn::A && winners[i] == Winner::A) {
                    winners[t] = Winner::A;
                } else {
                    bool hit_a = false;
                    bool hit_b = false;
                    bool hit_none = false;
                    for (int k = 0; k < N; ++k) {
                        if (t >> k & 1) continue;
                        int u = t | (1 << k);
                        if (winners[u] == Winner::A) {
                            hit_a = true;
                        } else if (winners[u] == Winner::B) {
                            hit_b = true;
                        } else {
                            hit_none = true;
                        }
                    }
                    if (turns[t] == Turn::A) {
                        if (hit_a) {
                            winners[t] = Winner::A;
                        } else if (!hit_none) {
                            winners[t] = Winner::B;
                        }
                    } else {
                        if (hit_b) {
                            winners[t] = Winner::B;
                        } else if (!hit_none) {
                            winners[t] = Winner::A;
                        }
                    }
                }
                if (winners[t] != Winner::NONE) {
                    q.push(t);
                }
            }
        }
        // 判定结果
        return winners[0] == Winner::A;
    }
};
```

相较于记忆化搜索确实是慢了太多
![image.png](https://pic.leetcode-cn.com/baa21284e2c3a59dbb69651bbc58d750e5fbb3726a19eaa25c7bf8d1e3c6c38b-image.png)
