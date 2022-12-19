### 算法分析
1. 定义一个哈希表存储克隆过的节点
2. 递归调用node节点
3. 当node为空返回空
4. 当克隆过返回node节点对应的克隆节点
5. 否则克隆node节点cloneNode，并将<node, cloneNode>插入到哈希表中
6. 遍历node节点的neighbors节点，递归调用每个neighborNode，并将返回值加入cloneNode->neighbors中
7. 最后返回cloneNode
### 复杂度分析
+ 时间复杂度：O(n)，n表示节点个数
+ 空间复杂度：O(n+h)，n是哈希表需要的空间，大小为节点个数，h是递归调用栈的空间，大小为递归深度
### 源码
```C++ []
class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> visited;

        return cloneRecursive(node, visited);
    }

    Node* cloneRecursive(Node* node, map<Node*, Node*>& visited)
    {
        if (node == NULL)
            return NULL;

        map<Node*, Node*>::iterator iter = visited.find(node);
        if (iter != visited.end())
            return iter->second;

        Node* cloneNode = new Node(node->val);
        visited.insert(pair<Node*, Node*>(node, cloneNode));

        for (int i = 0; i < node->neighbors.size(); i++)
        {
            Node* neighborNode = node->neighbors[i];
            cloneNode->neighbors.push_back(cloneRecursive(neighborNode, visited));
        }

        return cloneNode;
    }
};