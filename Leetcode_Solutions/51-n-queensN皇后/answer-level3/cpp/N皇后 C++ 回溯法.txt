### 解题思路
基本的回溯法，其中比较关键的是斜对角的合法性判断。
算法的首先创建一个N*N的bool类型的二维数组Q，然后按行递归，按列迭代。
由于我是按行递归，所以不用记录行的合法性。
创建一个line数组，记录列的合法性；创建Incline1数组，记录/对角的合法性；创建Incline2数组，记录\对角的合法性。
列的合法性容易判断。而对角的合法性怎么判断呢？
如果我们遍历到Q[n][i]，如果Incline1[n-i+N-1]不为true，Incline2[n+i]也不为true，那么就是合法的。
至于Incline1和Incline2的索引为什么是那2个算式，可以自己算一下。

N皇后相比起解数独容易多了，由于某个位置，要么有皇后，要么没皇后，所以可以简单的用bool类型解决。
而数独有9个数字，需要依次判断，而且还需要判断子盘的合法性，子盘的合法性判断也挺麻烦的。
![image.png](https://pic.leetcode-cn.com/1544cffb8de4bffd4e085701fb77ba99f12e1b84bfaaea326f73391e9e448ee6-image.png)

### 代码

```cpp
class Solution {
private:
    int N;
    vector<vector<string>> res;
public:
    vector<vector<string>> solveNQueens(int n) {
        N=n;
        vector<bool> Line(n,false);
        vector<bool> Incline1(2*n-1,false);
        vector<bool> Incline2(2*n-1,false);
        vector<vector<bool>> Q(N,Line);
        nQueen(0,Q,Line,Incline1,Incline2);
        return res;
    }
    void nQueen(int n,vector<vector<bool>>& Q,vector<bool> &line,vector<bool> &Incline1,vector<bool> &Incline2)
    {
        if(n==N)//结束的标志，生成结果
        {
            string a="";
            vector<string> b;
            for(int i=0;i<N;i++) 
            {
                for(int j=0;j<N;j++)
                {
                    if(Q[i][j]) a.push_back('Q');
                    else a.push_back('.');
                }
                b.push_back(a);
                a.clear();
            }
            res.push_back(b);
            return;
        }
        for(int i=0;i<N;i++)
            if(!line[i] && !Incline1[n-i+N-1] && !Incline2[n+i])
            {
                Incline1[n-i+N-1]=true;
                Incline2[n+i]=true;
                Q[n][i]=true;
                line[i]=true;

                nQueen(n+1,Q,line,Incline1,Incline2);

                Incline1[n-i+N-1]=false;
                Incline2[n+i]=false;
                Q[n][i]=false;
                line[i]=false;
            }
    }
};
```