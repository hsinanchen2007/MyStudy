本题要求总的有多少个点符合要求，本质是个搜索问题。搜索问题可以用 BFS 或者 DFS，都有相应的模板。

我在博客中已经总结了所有常见的算法模板，[【LeetCode】代码模板，刷题必会](https://blog.csdn.net/fuxuemingzhu/article/details/101900729)，直接拿来用！

BFS使用队列，把每个还没有搜索到的点一次放入队列，然后再弹出队列的头部元素当做当前遍历点。

如果不需要确定当前遍历到了哪一层，BFS模板如下。

```
while queue 不空：
    cur = queue.pop()
    for 节点 in cur的所有相邻节点：
        if 该节点有效且未访问过：
            queue.push(该节点)
```

如果要确定当前遍历到了哪一层，BFS模板如下。这里增加了level表示当前遍历到二叉树中的哪一层了，也可以理解为在一个图中，现在已经走了多少步了。size表示在开始遍历新的一层时，队列中有多少个元素，即有多少个点需要向前走一步。

```
level = 0
while queue 不空：
    size = queue.size()
    while (size --) {
        cur = queue.pop()
        for 节点 in cur的所有相邻节点：
            if 该节点有效且未被访问过：
                queue.push(该节点)
    }
    level ++;
```

上面两个是通用模板，在任何题目中都可以用，是要记住的！


本题不需要记录遍历到多少层，只需要统计总的遍历了多少个点，因此使用模板一。

保存一个点是否遍历过：使用了visited数组，如果一个点放入队列，那么同时就设置其已经visited了。

直接使用模板，C++代码如下：


```cpp
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        q.push({0, 0});
        int res = 0;
        visited[0][0] = 1;
        while (!q.empty()) {
            auto front = q.front(); q.pop();
            int x = front.first;
            int y = front.second;
            res += 1;
            for (auto d : directions) {
                int new_x = x + d.first;
                int new_y = y + d.second;
                if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n 
                    || visited[new_x][new_y] == 1 ||
                    sumDigit(new_x, new_y) > k) {
                    continue;
                }
                q.push({new_x, new_y});
                visited[new_x][new_y] = 1;
            }
        }
        return res;
    }
    int sumDigit(int i, int j) {
        int sum = 0;
        while (i > 0) {
            sum += i % 10;
            i /= 10;
        }
        while (j > 0) {
            sum += j % 10;
            j /= 10;
        }
        return sum;
    }
private:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};
```


欢迎关注[负雪明烛的刷题博客](https://blog.csdn.net/fuxuemingzhu)，刷题800多，每道都记录了写法！

力扣每日一题活动建群啦，一起监督和讨论，我自建监督网址：[http://group.ojeveryday.com/#/check](http://group.ojeveryday.com/#/check)，加入方式可以在监督网址中看到。

目前已经有 330+ 人加入了，就差你了！

![image.png](https://pic.leetcode-cn.com/83cb9ae652e6ace652e90e459d0f39fff5c627b73373cd44f279b0aca2e321de-image.png)
