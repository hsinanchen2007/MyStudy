先按cost从小到大排序，然后依次尝试构造并查集。
性能不佳，小菜鸟最近在练习并查集。仅限于坚决问题

```
class UnionFind {
private:
    vector<int> rootTable;
public:
    explicit UnionFind(int num)
    {
        rootTable.assign(num, -1);
    }

    int FindRoot(int index)
    {
        if (rootTable[index] == -1) {
            return index;
        }
        return rootTable[index] = FindRoot(rootTable[index]);
    }

    void Union(int indexI, int indexJ)
    {
        int rootI = FindRoot(indexI);
        int rootJ = FindRoot(indexJ);
        if (rootI != rootJ) {
            rootTable[rootI] = rootJ;
        }
    }
};

const int COST_POSITION = 2;

class Solution {
private:
    static bool compare(vector<int> connection1, vector<int> connection2)
    {
        return connection1[COST_POSITION] < connection2[COST_POSITION];
    }

public:
    int minimumCost(int N, vector<vector<int>> &connections)
    {
        if (connections.empty()){
            return 0;
        }
        int cost = 0;
        int lineNum = 0;
        sort(connections.begin(), connections.end(), compare);
        UnionFind uf(N + 1);
        for(const vector<int> &connection: connections){
            int nodeX = connection[0];
            int nodeY = connection[1];
            if (uf.FindRoot(nodeX) != uf.FindRoot(nodeY)){
                uf.Union(nodeX, nodeY);
                cost += connection[COST_POSITION];
                ++lineNum;
            }
            if (lineNum == N-1){
                break;
            }
        }
        if (lineNum < N - 1){
            cost = -1;
        }
        return cost;
    }
};
```
