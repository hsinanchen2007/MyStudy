### 解题思路
先做预处理。因为这种一个格子的确实不好弄，一种思路是将题目中的一个格子分成2x2的4个格子来做。但是这样内存就会涨4倍。
题解里面另外一种做法是将题目中N*N的grid里面的一个点映射到另外一个（size+1）*（size+1)的表格上。
怎么理解这个size+1呢？
你先画一个2x2的图，然后它的交点是有3x3个的，让每个交点负责填充它右下的方格（最右边和最下边的交点就不用负责填充）。这样N*N的题目矩阵就可以填充(N+1)*(N+1)个交点的表格（这个表格只有N*N个方格）
遇到'/'，则把它右方和下方的交点连接在一起；遇到'\'则把它自己和它右下方的交点连接在一起
然后运用查并集的方法统计集合数目。

### 代码

```cpp
class Solution {
public:
    vector<int> parent;
    
    void init(int size) {
        for (int i=0; i<size; i++) {
            parent.emplace_back(i);
        }
    }
    
    int find(int i) {
        while (i != parent[i]) {
            i = find(parent[i]);
        }
        return i;
    }
    
    void merge(int i, int j) {
        int m = find(i);
        int n = find(j);
        parent[m] = n;
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int size = (int)grid.size();
        init((size + 1) * (size+1));
        for (int i=0; i<=size; i++) { //第一行
            merge(0, i);
        }
        for (int i=0; i<=size; i++) { //最左边一列
            merge(0, (size+1) * i);
        }
        for (int i=0; i<=size; i++) { //最右边一列
            merge(0, (size+1) * i + size);
        }
        for (int i=0; i<=size; i++) { //最下边一行
            merge(0, (size+1) * size + i);
        }
        //这里是用这种思路查并集：题目中N*N的grid里面的一个点映射到另外一个（size+1）*（size+1)的表格上。怎么理解这个size+1呢
        //你先画一个2x2的图，然后它的交点是有3x3个的，让每个交点负责填充它右下的方格。这样N*N的题目矩阵就可以填充(N+1)*(N+1)的表格
//        遇到'/'，则把它右方和下方的交点连接在一起；遇到'\'则把它自己和它右下方的交点连接在一起
        int res = 1;
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                if (grid[i][j] == '/') {
                    int m = find((i+1)*(size+1) + j);
                    int n = find(i*(size+1) + j+1);
                    if (m == n) {
                        res++;
                    } else {
                        merge(m, n);
                    }
                } else if (grid[i][j] == '\\') {
                    int m = find(i*(size+1) + j);
                    int n = find((i+1)*(size+1) + j+1);
                    if (m == n) {
                        res++;
                    } else {
                        merge(m, n);
                    }
                }
            }
        }
        return res;
    }
};
```