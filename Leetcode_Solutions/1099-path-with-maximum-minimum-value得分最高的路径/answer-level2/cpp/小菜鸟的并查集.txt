学了并查集，就想一直用熟练。性能不好，仅限于完成题目。
相当于把节点值从大到小 逐个尝试，最后拼出来A[0, 0]到A[R, C]的通路。
先把矩阵节点按从大到小排序，然后逐个访问，尝试构造并查集。如果A[0, 0]和A[R, C]的root相同，认为有通路，终止。
```
class UnionFind {
private:
    vector<int> rootTable;
public:
    explicit UnionFind(size_t n)
    {
        rootTable.assign(n, -1);
    }
    int FindRoot(int elem)
    {
        if (rootTable[elem] == -1) {
            return elem;
        }
        return rootTable[elem] = FindRoot(rootTable[elem]);
    }

    void Union(int elem1, int elem2)
    {
        int rootElem1 = FindRoot(elem1);
        int rootElem2 = FindRoot(elem2);
        if (rootElem1 != rootElem2) {
            rootTable[rootElem1] = rootElem2;
        }
    }
};

class Solution {
private:
    typedef struct {
        int value{};
        pair<int, int> coordinate;
    } matrixNode;

    static bool compare(const matrixNode &node1, const matrixNode &node2)
    {
        return node1.value > node2.value;
    }

public:
    int maximumMinimumPath(vector<vector<int>> &A)
    {
        if (A.empty()) {
            return 0;
        }
        matrixNode node;
        vector<matrixNode> matrixNodes;
        // 矩阵中，每个节点构造成结构体matrixNode，存入vector
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A[0].size(); ++j) {
                node.value = A[i][j];
                node.coordinate = make_pair(i, j);
                matrixNodes.push_back(node);
            }
        }
        // 根据节点值的大小，对vector从大到小进行排序。
        sort(matrixNodes.begin(), matrixNodes.end(), compare);
        int rowNum = int(A.size());
        int colNum = int(A[0].size());

        int minValue = min(A[0][0], A[rowNum - 1][colNum - 1]);
        // 与输入矩阵相同大小的二维vector，用于记录是否已访问过
        vector<vector<int>> visited(A.size(), vector<int>(A[0].size(), 0));

        // 首尾记录为已访问,等待合并
        visited[0][0] = 1;
        visited[rowNum - 1][colNum - 1] = 1;

        int matrixBeginIndex = 1;
        int matrixEndIndex = rowNum * colNum;

        vector<vector<int>> directions = {{0,  1},
                                          {0,  -1},
                                          {1,  0},
                                          {-1, 0}};
        UnionFind uf(A.size() * A[0].size() + 1);
        // 从大到小遍历节点
        for (matrixNode sortedNode: matrixNodes) {
            int nodeX = sortedNode.coordinate.first;
            int nodeY = sortedNode.coordinate.second;
            int ufIndex = nodeX * colNum + nodeY + 1;
            visited[nodeX][nodeY] = 1;
            minValue = min(minValue, sortedNode.value);

            // 判断近邻节点是否已走过，如果已走过：合并Union
            for (const vector<int> &direction: directions) {
                int neighborX = nodeX + direction[0];
                int neighborY = nodeY + direction[1];
                if (neighborX >= 0 && neighborX < rowNum && neighborY >= 0 && neighborY < colNum &&
                    visited[neighborX][neighborY] == 1) {
                    int neighborIndex = neighborX * colNum + neighborY + 1;
                    uf.Union(ufIndex, neighborIndex);
                }
            }
            // 直到矩阵的begin和end的root相同：说明已经有通路，break
            if (uf.FindRoot(matrixBeginIndex) == uf.FindRoot(matrixEndIndex)) {
                break;
            }
        }
        return minValue;
    }
};

```
