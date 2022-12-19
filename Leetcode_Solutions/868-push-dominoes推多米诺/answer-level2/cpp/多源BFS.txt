我们从所有不为'.'的位置开始进行BFS，同时记录每个位置被计算的轮次。

当前为'L'的位置，需要向左一位进行搜索；当前为'R'的位置，需要向右一位进行搜索。这里用一个`map`进行处理。

那么受力平衡的位置怎么处理呢？我们可以注意到，受力平衡的位置，其左边和右边的位置，一定在同一轮被计算。所以我们在进行搜索时，如果发现某一个位置的轮次已经被设置为当前轮次的下一轮，说明它已经在另一边受到了力。这时我们把对应位置还原为'.'即可。

参考代码
```cpp
map<char, int> dx = {{'L', -1}, {'R', 1}};

class Solution {
public:
    string pushDominoes(string d) {
        queue<int> q;
        vector<int> step(d.size());
        for (int i = 0; i < d.size(); ++i) 
            if (d[i] != '.') {
                q.push(i);
                step[i] = 1;
            }
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            if (d[f] == '.') continue;
            int nf = f + dx[d[f]];
            if (nf < 0 || nf >= d.size())
                continue;
            if (step[nf] == 0) {
                step[nf] = step[f] + 1;
                d[nf] = d[f];
                q.push(nf);
            } else if (step[nf] == step[f] + 1) {
                d[nf] = '.';
            }
        }
        return d;
    }
};
```