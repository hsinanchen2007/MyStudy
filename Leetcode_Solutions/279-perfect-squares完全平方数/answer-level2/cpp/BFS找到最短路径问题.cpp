```
class Solution {
public:
    int numSquares(int n) {
        //这是一个求最少的题目，用广度优先搜索，找到最短路径
        queue<int> q;
        vector<int> d(n+1,INT_MAX);
        q.push(0);
        d[0] = 0;
        //从0开始
        while(q.size()){
            int t = q.front();
            q.pop();
            //如果得到了所需的结果，break循环
            if(t == n) break;
            //更改路径，找到符合条件的i，加到当前的t上
            for(int i = 1; i*i + t<=n;i++){
                int j = i*i + t;
                //如果步长超越了一步，则更新，因为可以找到一个最优解
                if(d[j] > d[t] + 1){
                    d[j] = d[t] + 1;
                    q.push(j);
                }
            }
        }
        return d[n];
    }
};
```
