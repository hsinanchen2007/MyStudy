核心思想： 并查集，归并过程中，发现一条边的两个节点已经处于同一个子集，那就说明冗余边找到了，且正好是题目要求的，冗余（环路）上最后一个被发现冗余的边。

核心代码，是不是很简略，把我自己都惊讶到了：
```cpp
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // 初始化并查集， 题目条件可知， 一共有N个节点 一棵树和一个冗余（回路）， 所以N = edges.size()
        UnionFindSets ufs(edges.size());
        // 根据输入循环归并，遇到无法归并的两节点所在edge，说明这条边在并查集的同一个子集中。也就说明了冗余出现。
        for (auto e: edges) { if (ufs.Union(e[0], e[1]) < 0 ) { return e; } }
        // 以下语句，按题目说明的正常用例不可达。
        return {0, 0};
    }
};
```

并查集简单实现，注意union的返回值：

```cpp
using namespace std;

class UnionFindSets {
public:
    virtual ~UnionFindSets() = default;
    explicit UnionFindSets(int count) {
        m_vParents.resize(count+1);
        for (int i = 0; i <= count; i++) { m_vParents[i] = i; }
    };
    int Find(int x) {
        while(x != m_vParents[x]) { m_vParents[x] = m_vParents[m_vParents[x]]; x = m_vParents[x]; };
        return x;
    };
    int Union(int a, int b) {
        int rootA = Find(a);
        int rootB = Find(b);
        if (rootA == rootB) { return -1; };
        m_vParents[rootA] = rootB;  // merge a tree to b.
        return 0;
    }
private:
    vector<int> m_vParents;
    // vector<int> m_vR;
};
```

简单的测试用例，注意线下测试是，class为 RedundantConnection，继承自MyDebug：
```cpp
int RedundantConnection_Tester()
{
    vector<vector<int>> edges{ {1, 2}, {1, 3}, {2, 3} };
    vector<int> result;
    RedundantConnection rc;
    rc.PrintVector2(edges, "input");
    result = rc.findRedundantConnection(edges);
    rc.PrintVector(result, "result");
    return 0;
}
```

