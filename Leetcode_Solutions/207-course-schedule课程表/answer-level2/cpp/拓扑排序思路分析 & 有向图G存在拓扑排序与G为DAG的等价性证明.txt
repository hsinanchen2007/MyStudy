# 课程表

现在你总共有 n 门课需要选，记为 0 到 n-1。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]

给定课程总量以及它们的先决条件，判断是否可能完成所有课程的学习？

------
写在前面：平时也会写一些题解收录在自己的Blog里。由于已经有很多人分享过每道题的详细解法了，所以我一般不会把它们贴在leetcode的题解区。但是我一直觉得算法的数学证明也是非常重要的一环，所以我会尽量把我认为有意义的证明整理在leetcode的题解区，补上这一块的空白，希望能对大家有所帮助。

## 拓扑排序

> **Topological Order**:  A topological order of a directed graph G = (V, E) is an ordering of its
> nodes as $v_1,..,v_n$ so that for every edge $(v_i,v_j)$ we have for $i<j$.

拓扑排序的一个经典应用案例。

关于拓扑排序有一个重要结论——一个有向图存在拓扑排序的充分必要条件是该图不存在有向环（DAG）。这个结论的具体证明由一下几个引理构成。

> Lemma1. If G has a topological ordering, then G is a DAG

引理1通过构造矛盾容易证明。

> Lemma2. If G is DAG, then G has a node with no entering edges.

如果每个点入度均大于0，由于节点数有限，总是能找到一个环，矛盾！

> Lemma3. If G is DAG, then G has a topological ordering.

递归构造

1. Base: n = 1 时，显然正确

2. 若n = k时，结论成立。

   n = k+1时，由Lemma1可以找到一个入度为0的节点v。G - { v } 是DAG（DAG删掉一个点显然还是DAG），由归纳假设得存在一个拓扑排序。因为v的入度为0，将v放在该排序前方即可得到一个有效排序。

## 算法实现

顺着证明的思路，我们不难发现，算法的关键就在入度为0的这些节点上。我们只需要不断地找出当前图中入度为0的点，并将其删除，更新其余点的入度即可确定该图是否存在拓扑排序。这是一个典型的贪心思想。

```c++
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> ajac(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        queue<int> qu;
        int cnt = 0;
        for(auto& pre: prerequisites)
        {
            ajac[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }    

        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                qu.push(i);
                cnt++;
            }
        }

        while(!qu.empty())
        {
            int cur = qu.front();
            qu.pop();
            for(int& succ: ajac[cur])
            {
                indegree[succ]--;
                if(indegree[succ] == 0)
                {
                    cnt++;
                    qu.push(succ);
                }
                if(cnt == numCourses)
                    return true;
            }
        }
        return cnt == numCourses;

    }
};

```



