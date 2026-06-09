### 解题思路一 BFS算法 -- 队列实现
与12题相似，矩阵路径的求解方法可以归结为图或树的遍历/搜索方法，而图的通用搜索算法就是BFS(广度优先搜索)和DFS(优先搜索)。BFS算法使用队列实现，当图或树的根节点满足条件，就入队，如果它的子节点满足条件，子节点入队，根节点出队，重复上述操作。本题与12题不同的是，12题需要将节点添加到路径中，而本题只需要计算满足条件的节点数量。将根节点push到队列中初始化队列，同时初始化标志数组为true。使用BFS方法，当队列不为空，即取出队列的队首节点，并计数符加1，同时判断该节点的子节点是否满足题目条件，如果满足则push到队列的队尾，循环继续。本题从(0,0)开始，所以只需考虑向右(x+1,y)和向下(x,y+1)。
### 代码
```
class Solution {
public:
    int movingCount(int m, int n, int k) {
        std::vector<std::vector<bool>> visit(m, std::vector<bool>(n, false));
        int c = 0;
        std::queue<std::pair<int, int>> que;
        //(0,0)初始化队列
        std::pair<int, int> p = std::make_pair(0, 0);
        que.push(p);
        //true初始化标志数组
        visit[p.first][p.second] = true;
        bfs(m, n, k, c, visit, que);
        return c;
    }

private:
    int sum(int n) {
        int s = 0;
        while (n > 0){
            s += n%10;
            n /= 10;
        }

        return s;
    }

    void bfs(int m, int n, int k, int &count, std::vector<std::vector<bool>> &visit,
    std::queue<std::pair<int, int>> &que) {
        std::pair<int, int> p(0, 0);
        while (!que.empty()) {
            //取出队首节点
            p = que.front();
            que.pop();
            //将计数+1
            count++;
            if (p.first + 1 >= 0 && p.first + 1 < m && p.second >= 0 && p.second < n &&
                sum(p.first + 1) + sum(p.second) <= k && !visit[p.first + 1][p.second]) {
                que.push({p.first + 1, p.second});
                visit[p.first + 1][p.second] = true;
            }

            if (p.first >= 0 && p.first < m && p.second + 1 >= 0 && p.second + 1 < n &&
                sum(p.first) + sum(p.second + 1) <= k && !visit[p.first][p.second + 1]) {
                que.push({p.first, p.second + 1});
                visit[p.first][p.second + 1] = true;
            }
        }
    }
};
```


### 解题思路二 DFS算法 -- 回溯
12题使用的DFS深度优先搜索和回溯算法本题也能使用，与BFS不同的是，DFS遍历节点时，满足本题条件则计数符加1，并设置该节点标志为true，同时判断该节点的子节点是否也满足本题条件，进行递归操作。DFS的思路要比BFS的思路要清晰一下，但本质是一样的，实测结果是：BFS 4ms,DFS 8ms。
### 代码
```cpp
class Solution {
public:

    int movingCount(int m, int n, int k) {
        //初始化标志数组
        std::vector<std::vector<bool>> visit(m, std::vector<bool>(n, false));
        //计数符
        int c = 0;
        dfs(m, n, k, 0, 0, c, visit);
        return c;
    }

private:
    //计算整数位数和函数
    int sum(int n) {
        int s = 0;
        while (n > 0) {
            s += n % 10;
            n /= 10;
        }

        return s;
    }

    //深度优先搜索
    void dfs(int m, int n, int k, int i, int j, int &count, std::vector<std::vector<bool>> &visit) {
        //满足位数和小于k
        if (sum(i) + sum(j) <= k) {
            //满足条件的数量+1
            count++;
            //该格子被访问过
            visit[i][j] = true;

            //判断向右+1：(i+1, j)，在矩阵内，且未被访问过
            if (i + 1 >= 0 && i + 1 < m && j >= 0 && j < n && !visit[i + 1][j]) {
                dfs(m, n, k, i + 1, j, count, visit);
            }
            //判断向下+1：(i, j+1)，在矩阵内，且未被访问过
            if (i >= 0 && i < m && j + 1 >= 0 && j + 1 < n && !visit[i][j + 1]) {
                dfs(m, n, k, i, j + 1, count, visit);
            }
        }
    }
};
```