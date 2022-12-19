### 解题思路
**判断解是否可行的条件**
我们从第一行开始放皇后，第一行有n个位置可以放，我们用x[1]来表示第一行的皇后所在的列，第二行有n-1个位置可以放，我们用x[2]来表示第二行皇后所在的列······因此，我们用一个数组x[n]来表示问题的解，x[i]表示皇后i放在第i行第x[i]列。
**x[i]≠x[j]，i≠j**
     
如何保证任何两个皇后不再一条斜线上？设两个皇后q1和q2放在（i，j）和（k，l）位置上，如果q1和q2在斜率为-1的对角线上，那么i - j = k - l成立，如果在斜率为1的对角线上，那么i + j = k + l成立，由此可知只要 | i - k | ≠ | j - l |成立，q1和q2就不再同一条斜线上。
**| i - k | ≠ | j - l |**   

![image.png](https://pic.leetcode-cn.com/1673db8f9c06deaf402642d2cda8689e6c70bf8a23db91695fce0da2aad3edce-image.png)

### 代码

```cpp
class Solution {
private:
    vector<vector<string>> res;//存储结果
    int nq;//n皇后个数
public:
    vector<vector<string>> solveNQueens(int n) {
        this->nq = n;
        vector<int> x(n+1, 0);//用于记录第一个皇后到第n个皇后所放置的位置（列号）
        backTrack(x, 1);//回溯
        return res;
    }
    bool place(vector<int> x, int k){//判断皇后所放置的位置合不合法（剪枝函数）
        for(int j = 1; j < k; j++){//对前k个已经放置的皇后针对当前位置判断其合法性
            if(abs(k-j) == abs(x[j] - x[k]) || (x[k] == x[j])) return false;//斜率相等，处于同一列则不合法
        }
        return true;
    }
    void backTrack(vector<int> &x, int k){
        if(k > nq){//回溯出口，存储解法
            vector<string> qp;
            for(int i = 1; i <= nq; i++){
                string tmp = "";
                for(int j = 1; j <= nq; j++){
                    if(x[i] == j){
                        tmp += 'Q';
                    }else{
                        tmp += '.';
                    }
                }
                qp.push_back(tmp);
            }
            res.push_back(qp);
        }else{
            for(int i = 1; i <= nq; i++){//对n个皇后的每一个位置进行试探
                x[k] = i;
                if(place(x, k)) backTrack(x, k + 1);//合法则放下一个皇后
            }
        }
    }
};
```