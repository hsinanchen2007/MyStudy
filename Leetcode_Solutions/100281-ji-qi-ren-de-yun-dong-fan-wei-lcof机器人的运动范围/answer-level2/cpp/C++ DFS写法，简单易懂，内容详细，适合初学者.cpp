拿到这道题，我一开始就踩了个坑,直接二重循环遍历整个数组判断与k的值，后来仔细读题以后才发现并不是这样.
这道题本质就是考走水坑，走过的地方标记上1，没走过的地方标记为0，这样做的目的是为了不重复走.
```
class Solution {
public:
    bool map[100][100];
    int movingCount(int m, int n, int k) {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                map[i][j] = 0;
        return dfs(0, 0, m, n, k);
    }
    int dfs(int x, int y, int m, int n, int k) {
        if (map[x][y] == 1 || x < 0 || y < 0 || x >= m || y >= n || (x / 10 + x % 10 + y / 10 + y % 10) > k)
            return 0;
        map[x][y] = 1;
        return dfs(x + 1, y, m, n, k) + dfs(x, y + 1, m, n, k) + 1;
    }
};
```
其实这道题的关键点在于return后面的写法，其实如果仔细一步步走，有助于理解，但是DFS写多了会发现：
dfs(x + 1, y, m, n, k) + dfs(x, y + 1, m, n, k) + 1最终返回的就是x向右走,向下走的数目，而这个数目由最后的+1实现.
其中还有要注意的就是dfs的判定条件，先判定，后return，掌握好判定条件,和return的值，就能逐渐熟练了.
