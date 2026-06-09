### 思路
1. 需要先将“我的领导是谁”这张数据表转换成“我是领导，我手下有谁谁谁”这样的表
2. 这样就可以一层一层往下找了
3. 那么用 bfs 还是 dfs
4. 考虑到一种情况，`0` 手下 1 和 2 ， `1` 的时间是 2s ，而 `2` 的时间是 5s 。从此之后再下级的时间就不一样了。
5. 使用 bfs 处理上会更麻烦一点
6. 所以使用 dfs

### 用例
```
输入：n = 7, headID = 0, manager = [-1,0,0,1,3,2,5], informTime = [1,2,5,2,0,1,0]
输出：7
```

### 图解
![图片.png](https://pic.leetcode-cn.com/5ed3aac62be83952392b9dfaa231dccf220d7d56a683d1a11551d4d0582a59e1-%E5%9B%BE%E7%89%87.png)

如 4 描述使用 bfs 需要注意的问题  
如果是最基本的 bfs 套路可能会遇到  
解决方法是将时间和节点同时存在队列里  

不过有点麻烦，我就选择了 dfs 

### 答题
```cpp
void dfs(vector<vector<int>>& mana, vector<int>& informTime, int id, int time, int& ans)
{
    if (mana[id].empty())
    {
        ans = max(ans, time);
        return;
    }
    time += informTime[id];
    for (auto& next : mana[id])
    {
        dfs(mana, informTime, next, time, ans);
    }
}

int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
{
    vector<vector<int>> mana(manager.size(), vector<int>());
    for (int i = 0; i < manager.size(); i++)
    {
        if (manager[i] == -1) continue;
        mana[manager[i]].push_back(i);
    }

    int ans = 0;
    dfs(mana, informTime, headID, 0, ans);
    return ans;
}
```


### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

