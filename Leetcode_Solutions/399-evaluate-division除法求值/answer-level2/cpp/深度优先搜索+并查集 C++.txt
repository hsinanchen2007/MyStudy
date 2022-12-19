## 解法1：带权无向图+深度优先搜索

阅读题目后，我们很容易对问题进行抽象：查找在带权无向图中是否存在从一个顶点`node1`到另一个顶点`node2`的路径。如果存在从`node1`到`node1`的路径，则将路径上的所有权重的乘积作为最终的结果返回。

查找带权无向图中是否存在某条路径的经典解决方法是深度优先搜索和广度优先搜索。这里使用深度优先搜索的方式实现。

在实现深度优先搜索时，有如下需要注意的点：

* 使用邻接表存储无向图：

  ```shell
  a -> b: 3.0
  b -> a: 1/3.0, c: 2.0
  c -> b: 0.5
  ```

* 需要对已经访问过的顶点进行标记，如果已经访问过则跳过。这一做法的目的是为了避免掉入无向图的环中，从而陷入死循环；
* 递归实现的终止条件是：如果当前顶点为目标顶点，则返回到从起始顶点到当前顶点的路径上的权重的乘积；
* 如果，在某一条路径上已经找到了目标顶点，则停止对剩余路径的递归。因为，一个顶点到另一个顶点的结果只有一个。

在进行代码实现时，要特别注意边界条件的检查。代码如下：

```c++
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        map<string, map<string, double>> adj_list;
        // 构建带权无向图的邻接表
        for (int i = 0; i < equations.size(); i++){
            string node1 = equations[i][0];
            string node2 = equations[i][1];
            double value = values[i];

            adj_list[node1][node2] = value;
            adj_list[node2][node1] = 1 / value;
        }

        vector<double> results;
        for (int j = 0; j < queries.size(); j++){
            string node1 = queries[j][0];
            string node2 = queries[j][1];

            if (adj_list.find(node1) == adj_list.end() || adj_list.find(node2) == adj_list.end()){
                results.push_back(-1);
                continue;
            }

            map<string, bool> visited;
            double temp_result = dfs(adj_list, node1, node2, 1.0, visited);
            results.push_back(temp_result);
        }
        return results;
    }

    double dfs(map<string, map<string, double>>& adj_list, string current_node, string target_node, double last_result, map<string, bool>& visited){
        if (current_node == target_node)
            return last_result;

        double result = -1;
        visited[current_node] = true;
        for (auto item: adj_list[current_node]){
            string child_node = item.first;
            double value = item.second;
            if (visited[child_node])
                continue;

            double temp_result = dfs(adj_list, child_node, target_node, last_result * value, visited);
            if (temp_result != -1){
                result = temp_result;
                break;
            }
        }
        return result;
    }
};
```

时间复杂度：$O(N+E)$，将所有顶点和边都访问一遍。

空间复杂度：$O(N)$，临时内存存储已经访问过的顶点。

## 解法2：并查集

利用并查集的特点，可以很容易判定两个元素是否可以相除得到结果。如果两个元素属于同一个集合，则说明可以相除。

在构建并查集时，如果`a / b = 3.0`，则令`a`为`b`的根节点，`a`对应的节点的值为`3.0`，`b`对应的节点的值为`1.0`；此时，如果新加入了一个等式`b / c = 2.0`，则首先初始化节点`c`，值为`1.0`。然后将节点`c`合并到`b`所在的集合中，合并时采取的方法是：将`b`所在的集合中的所有节点的值都扩大`2.0 * c.value / b.value`倍，这样`b`和`c`之间的值的大小就满足原先的倍数关系，同时`b`原先所处于的集合的所有元素之间的倍数关系都维持不变。

在计算一个新的等式时，如果等式的两个元素中有任何一个不在并查集中，则返回`-1`；如果两个元素的根节点不相等，说明无法计算两个元素之间的值，返回-1；否则返回两个元素所对应的节点的值的商即可。

```c++
struct Node {
    double value;
    Node* parent;
    Node(): parent(this) {};

    Node(double value): value(value), parent(this) {};
};

class UnionFindSet {
private:
    unordered_map<string, Node*> nodes;

public:
    UnionFindSet(){};

    Node* Find(Node* node) {
        if (node->parent != node){
            node->parent = Find(node->parent);
        }
        return node->parent;
    }

    bool Union(Node* node1, Node* node2, double num){
        Node* parent1 = Find(node1);
        Node* parent2 = Find(node2);
        if (parent1 == parent2)
            return false;

        // 将node1所在集合的所有节点的value都扩大ratio倍
        double ratio = node2->value * num / node1->value;
        for (auto item: nodes){
            if (Find(item.second) == parent1)
                item.second->value *= ratio;
        }

        parent2->parent = parent1;
        return true;
    }

    /**************************题目相关操作*****************************/
    double CalculateEquation(string str1, string str2){
        // 两个元素都在并查集内
        if (Include(str1) && Include(str2)){
            // 两个元素的根节点相同
            if (Find(nodes[str1]) == Find(nodes[str2])){
                return nodes[str1]->value / nodes[str2]->value;
            }
            else {
                return -1.0;
            }
        }
        return -1.0;
    }

    // 将除法运算的两个元素加入并查集中
    void InsertNode(string str1, string str2, double value){
        if (!Include(str1))
            nodes[str1] = new Node(value);
        if (!Include(str2))
            nodes[str2] = new Node(1.0);
        Union(nodes[str1], nodes[str2], value);
    }

    bool Include(string str){
        return nodes.find(str) != nodes.end();
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        UnionFindSet union_set;
        // 将各个除法的两个元素插入并查集中
        for (int i = 0; i < equations.size(); i++)
            union_set.InsertNode(equations[i][0], equations[i][1], values[i]);

        vector<double> results;
        for (int i = 0; i < queries.size(); i++){
            results.push_back(union_set.CalculateEquation(queries[i][0], queries[i][1]));
        }

        return results;
    }
};
```

时间复杂度：$O(1)$；

空间复杂度：$O(n)$，存储并查集节点的额外存储空间。