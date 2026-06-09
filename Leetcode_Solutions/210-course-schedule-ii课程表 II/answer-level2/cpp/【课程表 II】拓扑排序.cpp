### 思路
1. 拓扑排序
2. 入度：设有向图中有一结点 v ，其入度即为当前所有从其他结点出发，终点为 v 的的边的数目。
3. 出度：设有向图中有一结点 v ，其出度即为当前所有起点为 v ，指向其他结点的边的数目。
4. 每次从入度为 0 的结点开始，加入队列。入度为 0 ，表示没有前置结点。
5. 处理入度为 0 的结点，把这个结点指向的结点的入度 -1 。
6. 再把新的入度为 0 的结点加入队列。
7. 如果队列都处理完毕，但是和总结点数不符，说明有些结点形成环。

### 答题
```C++
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<int> inDegree(numCourses, 0);
    vector<vector<int>> lst(numCourses, vector<int>());
    for (auto v : prerequisites)
    {
        inDegree[v[0]]++;
        lst[v[1]].push_back(v[0]);
    }

    queue<int> que;
    for (auto i = 0; i < inDegree.size(); i++)
    {
        if (inDegree[i] == 0)
        {
            que.push(i);
        }
    }

    vector<int> ans;
    while (!que.empty())
    {
        auto q = que.front();
        que.pop();
        ans.push_back(q);

        for (auto l : lst[q])
        {
            if (--inDegree[l] == 0)
            {
                que.push(l);
            }
        }
    }

    return (ans.size() == numCourses) ? ans : vector<int>();
}
```


### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

