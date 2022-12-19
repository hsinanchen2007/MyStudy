### 解题思路
先直接走到距离小于等于7的地方，在用广度优先搜索算法搞定随后几步。
刚开始试先直接走到距离小于等于3的地方，但是对于(5,5)用例，发现多用了2步，因此BFS从更远的地方开始。

### 代码

```cpp
struct StNode {
    int x;
    int y;
    int steps;
};
class Solution {
private:
    void MakeNode(struct StNode &node, int x, int y, int steps)
    {
        node.x = x;
        node.y = y;
        node.steps = steps;
    };
    bool FindNode(vector<struct StNode> v, struct StNode n)
    {
        for (unsigned int i; i < v.size(); i++) {
            if (v[i].x == n.x && v[i]. y == n.y) {
                return true;
            }
        }
        return false;
    }

    int Distance(int x, int y, struct StNode &n)
    {
        return abs(x - n.x) + abs(y - n.y);
    }

    int DistanceX(int x, struct StNode &n)
    {
        return abs(x - n.x);
    }
    int DistanceY(int y, struct StNode &n)
    {
        return abs(y - n.y);
    }
public:
    int minKnightMoves(int x, int y)
    {
        if (x == 0 && y == 0) {
            return 0;
        }
        vector<struct StNode> visiting;
        vector<struct StNode> visited;
        struct StNode node;
        int step[8][2] = {
            {1, 2},
            {2, 1},
            {-1, -2},
            {-2, -1},
            {2, -1},
            {-1, 2},
            {1, -2},
            {-2, 1},
        };
        MakeNode(node, 0, 0, 0);
        x = abs(x);
        y = abs(y);

        while (Distance(x, y, node) > 7) {
            if ((x - node.x) >= (y - node.y)) {
                node.x += 2;
                if (node.y < y) {
                    node.y++;
                } else {
                    node.y--;
                }
            } else {
                node.y += 2;
                if (node.x < x) {
                    node.x++;
                } else {
                    node.x--;
                }
            }
            node.steps++;
        }

        visiting.push_back(node);

        while(!visiting.empty()) {
            struct StNode n = visiting.front();
            visiting.erase(visiting.begin());
            visited.push_back(n);
            for (int i = 0; i < 8; i++) {
                MakeNode(node,
                        n.x + step[i][0],
                        n.y + step[i][1],
                        n.steps + 1);
                if (node.x == x && node.y == y) {
                    return node.steps;
                }

                if (FindNode(visiting, node)) {
                    continue;
                }
                if (FindNode(visited, node)) {
                    continue;
                }
                //printf("%d,(%d-%d)\n", node.steps, node.x, node.y);
                visiting.push_back(node);
            }
        }
        return 0;
    }
};
```