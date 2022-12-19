根据题目的描述和示例，我们首先应该想到本题很适合图的算法。那么我们就以图的形式将题目中的信息建模。
- 令 $G(V, E)$ 为一个有向，无权图。
- 每门课程为图中的一个结点。
- 根据课程之间的先修关系对边进行建模。问题中给出的 `relations[i] = [X, Y]` 的二元组代表课程 `X` 是课程 `Y` 的先修课程。这可以用一条有向边表示。
- 图 $G$ 有可能是循环图，如果是循环图，则不可能完成所以课程。

下面我们根据一个示例来建图，示例为 `relations = [[0,2],[1,3],[2,1],[2,3],[2,4],[3,5],[6,5]`。
![image.png](https://pic.leetcode-cn.com/61f3129ad890af2549ee14db4f9b7308cfaf911b248bbdc7bac1b918f193f7b6-image.png){:width=300} {:align="center"}

对于上述图，可能的一种上课方法是：`0 6 2 1 4 3 5`，还有一种可能的方法为：`0 2 1 3 4 5 6`。当然还有其他可能的方法。这是两种不同的排序方法，第一种是根据拓扑排序，第二种则是深度优先遍历的方法。本题使用第一种方法更加合适。

#### 方法一：拓扑排序

**思路**

这题其实是典型的有优先级限制的调度问题，我们可以使用**拓扑排序**来解决这样的问题。

我们知道只有当一门课程没有前置课程的时候，才能上这门课。我们可以把这门课程需要上的前置课程的数量表示为**入度**。比如上图中 `0` 的入度为 0，没有前置课程需要上，而 `3` 的入度为 2，有 `1` 和 `2` 需要上。所以我们可以每一次遍历把所有入度为 0 的课程上完，并且把他们的后置课程的入度减 1，重复这个过程直到没有课程可以上。

**算法**
1. 初始化所有课程的入度 `preClassCount`和直接后置课程 `nextClasses`。
2. 初始化 `term` 记录一共遍历了几次，一次代表一个学期。
3. 找出所有入度为 0 的课程，记录为已学习 `learn`。
4. 将所有这学期已学习的课程的直接后置课程的入度减 1。
5. 重复第三步直到所有课程已经学完，或者这个学期不能学习任何课程。

在进入正式实现之前，先让我们通过示例图查看算法的运行过程。
![fig1](https://assets.leetcode-cn.com/solution-static/1136_fig1.gif)

**代码**

```Golang [ ]
// 将 1 到 N，改成 0 到 N - 1，方便数组索引
func minimumSemesters(N int, relations [][]int) int {
    preClassCount := map[int]int{}
    nextClasses := make([][]int, N)
    for i := 0; i < N; i++ {
        preClassCount[i] = 0
    }
    for _, r := range relations {
        nextClasses[r[0]-1] = append(nextClasses[r[0]-1], r[1]-1) // 记录后置课程
        preClassCount[r[1]-1]++ // 计算初始入度
    }
    term := 0
    for len(preClassCount) > 0 {
        term++
        learn := []int{}
        for class, count := range preClassCount {
            if count == 0 {
                learn = append(learn, class) // 入度为 0，可以学习
            }
        }
        if len(learn) == 0 { // 没有课程可以学了，说明有循环
            return -1
        }
        for _, l := range learn {
            delete(preClassCount, l)
            for _, class := range nextClasses[l] {
                preClassCount[class]--
            }
        }
    }
    return term
}
```

```Python3 [ ]
class Solution:
    def minimumSemesters(self, N: int, relations: List[List[int]]) -> int:
        pre_class_cnt = [0] * N
        next_classes = [[] for i in range(N)]
        for a, b in relations:
            pre_class_cnt[b - 1] += 1
            next_classes[a - 1].append(b - 1)
        learn = [i for i in range(N) if pre_class_cnt[i] == 0]
        term = 0
        while learn:
            next_semester = []
            for cur_class in learn:
                for next_class in next_classes[cur_class]:
                    pre_class_cnt[next_class] -= 1
                    if pre_class_cnt[next_class] == 0:
                        next_semester.append(next_class)
            learn = next_semester
            term += 1
        if sum(pre_class_cnt) > 0:
            return -1
        return term
```

```C++ [ ]
class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        int in[N] = {0};
        vector<vector<int>> edges(N);
        for (auto relation : relations) {
            int x = relation[0] - 1;
            int y = relation[1] - 1;
            edges[x].push_back(y);
            edges[y].push_back(x);
            ++in[y];
        }
        auto cur_semester = new vector<int>;
        for (int i = 0; i != N; ++i)
            if (in[i] == 0)
                cur_semester -> push_back(i);
        int term = 0;
        while (!cur_semester -> empty()) {
            auto next_semester = new vector<int>;
            for (int cur_class : *cur_semester)
                for (int next_class : edges[cur_class]) {
                    if (0 == --in[next_class])
                        next_semester -> push_back(next_class);
                }
            delete cur_semester;
            cur_semester = next_semester;
            ++term;
        }
        for (int n : in)
            if (n > 0)
                return -1;
        return term;
    }
};
```

**复杂度分析**

- 时间复杂度：$O(E + V)$。这里 $E$ 表示邻边的条数，$V$ 表示结点的个数。初始化入度为 0 的集合需要遍历整张图，具体做法是检查每个结点和每条边，因此复杂度为 $O(E + V)$，然后对该集合进行操作，又需要遍历整张图中的每个结点和每条边，复杂度也为 $O(E+V)$。

- 空间复杂度：$O(E + V)$。这里 $E$ 表示邻边的条数，$V$ 表示结点的个数。入度数组长度为节点个数 $V$，二维数组记录后置节点的长度为 $E$。