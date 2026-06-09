### 解题思路
扣破头都不知道怎么一个个的合并二维坐标,开始一直想如何把新的点和之前点联系起来,怎么做都不好实现.
看到解题思路,居然可以分别把x,y+10000来作为两个点处理,先合并在一起. 然后新增加的点通过相同的合并操作,把之前添加的点再合并在一起,这操作简直惊为天人.

实现参考算法4,加了加权路径合并,再加上路径压缩.


### 代码

```cpp
const int MAX_LINE = 10000;

class Solution {
public:
    int removeStones(vector<vector<int> > &stones)
    {
        count = stones.size();
        int i;
        for (i = 0; i < MAX_LINE * 2; ++i) {
            parent[i] = i;
            sz[i] = 1;
        }
        for (i = 0; i < stones.size(); ++i) {
            Join(stones[i][0], stones[i][1] + MAX_LINE);
        }
        set<int> list;
        for (i = 0; i < stones.size(); ++i) {
            if (FindRoot(stones[i][0]) == stones[i][0]) {
                if (list.find(stones[i][0]) == list.end()) {
                    list.insert(stones[i][0]);
                    count--;
                }
            }
        }
        return count;
    }

private:
    int parent[MAX_LINE * 2];
    int sz[MAX_LINE * 2];
    int count;
    int FindRoot(int node)
    {
        while (node != parent[node]) {
            parent[node] = parent[parent[node]]; // 路径压缩
            node = parent[node];
        }
        return node;
    }
    void Join(int p, int q)
    {
        int pRoot = FindRoot(p);
        int qRoot = FindRoot(q);
        if (pRoot == qRoot) {
            return;
        }
        if (sz[pRoot] < sz[qRoot]) { // 加权路径合并
            parent[pRoot] = qRoot;
            sz[qRoot] += sz[pRoot];
        } else {
            parent[qRoot] = pRoot;
            sz[pRoot] += sz[qRoot];
        }
        return;
    }
};
```