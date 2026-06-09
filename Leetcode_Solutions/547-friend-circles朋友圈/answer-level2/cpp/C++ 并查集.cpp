### 解题思路
数组a保存节点之间的关系
最开始a[i]=i,每个节点的根节点都是自己
遍历M(这里注意，因为矩阵的右上半部分就可以描述所有朋友关系，因此不需要遍历全部元素)
如果当前元素为1, 就判断索引值a1和a2是否根相同，不相同就合并, 比如说M[0][1]=1, 而a[0] = 0, a[1] = 1, 根不同需要合并，变成a[0]=1, 表示0的上一级是1,
最后统计下a[i]==i的元素个数，就是不同的朋友圈的个数

### 代码

```cpp
class Solution {
public:
    // 朋友圈
    // a[3]=2 表示3号的上一级是2
    int findRoot(int num, vector<int> &a) {
        while (a[num] != num) {
            num = a[num];
        }
        return num;
    }
    void join(int x, int y, vector<int> &a) {
        int f1 = findRoot(x, a);
        int f2 = findRoot(y, a);
        // 如果根不一样就合并
        if (f1 != f2) {
            a[f1] = f2;
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        // 使用并查集
        int size = M.size();
        vector<int> a(size, 0);

        for (int i = 0; i < size; ++i) {
            // 最开始，每个元素的父节点都是自己
            a[i] = i;
        }
        for (int j = 0; j < size; ++j) {
            for (int k = j; k < size; ++k) {
                if(j != k && M[j][k]) {
                    join(j, k, a);
                }
            }
        }
        int result = 0;
        for (int l = 0; l < size; ++l) {
            if(a[l] == l) {
                result++;
            }
        }
        return result;
    }
};
```