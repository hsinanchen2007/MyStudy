## 问题描述
对于一个具有树特征的无向图，我们可选择任何一个节点作为根。图因此可以成为树，在所有可能的树中，具有最小高度的树被称为最小高度树。给出这样的一个图，写出一个函数找到所有的最小高度树并返回他们的根节点。

格式

该图包含 `n` 个节点，标记为 `0` 到 `n - 1`。给定数字 `n` 和一个无向边 `edges` 列表（每一个边都是一对标签）。

你可以假设没有重复的边会出现在 `edges` 中。由于所有的边都是无向边， `[0, 1]和 [1, 0]` 是相同的，因此不会同时出现在 `edges` 里。

![](https://pic.leetcode-cn.com/ac0062b543af9ca3b5c59fcc0e55d9dfcd94ea870e8f8a17f91619e084fe84e4.png)

[最小高度树](https://leetcode-cn.com/problems/minimum-height-trees/ "最小高度树")

## 解决方法
### 拓补排序

类似于[课程表](https://liyiping.cn/article/course-schedule/ "课程表")这道题，主要思想就是逐步剔除叶子节点，直至达到符合要求。

![](https://pic.leetcode-cn.com/1560b3ae12b5ea0f4637d67a8e3c97e0263e62789498d5faf8e8954f1ec92a9c.png)

结合代码比较好理解

```cpp

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1 && edges.size()==0)return {0};//面向测试用例编程
        vector<int>res;
        vector<int>indegree(n);
        vector<vector<int>> graph(n,vector<int>());
        queue<int>q;

        //构造临接表
        for(auto item:edges){
            graph[item[0]].push_back(item[1]);
            graph[item[1]].push_back(item[0]);
        }

        //构造入度表
        for(auto item:edges){
            indegree[item[0]]++;
            indegree[item[1]]++;
        }

        //将叶子节点，也就是入度数为1的点加入队列
        for(int i=0;i<n;i++){
            if(indegree[i]==1)q.push(i);
        }
        while(n>2){
            int count=q.size();
            n-=count;
            //每次将所有的叶子节点去除，并且将新的叶子节点加入队列
            while(count--){
                int item=q.front();
                q.pop();
                int size=graph[item].size();
                for(int i=0;i<size;i++){
                    //既然是无向边，那么要将两个节点的入度数都要减一
                    --indegree[item];
                    --indegree[graph[item][i]];
                    //将新的叶子节点入队
                    if(indegree[graph[item][i]]==1)q.push(graph[item][i]);
                }
            }
        }

        //此时队列中的节点便是要返回的值，不论是一个还是两个节点。
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        
        return res;
    }
};
```



my site:[https://liyiping.cn](https://liyiping.cn)