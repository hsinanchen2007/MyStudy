### 解题思路

通过广度优先的方法按层遍历树，算法如下

- 外层循环，遍历所有的node
  - 获取当前层的Node数
  - 创建一个临时tmp，赋值为NULL
  - 内层循环，根据Node数，遍历当前层所有Node
    - 获取当前的node
    - 如果node为空，跳过后续操作
    - 如果node不为空，将当前节点的next指向tmp
    - 将tmp赋值为当前节点
    - 加入当前节点的right和left（因为每次是先右后左，因此从queue取出的时候也是先右后左，因此就能够将left的next指向right

### 代码

```cpp
class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL ) return root;

        queue<Node*> q;
        q.push(root);

        while ( ! q.empty() ){
            int q_size = q.size();
            Node *tmp = NULL;
            while ( q_size-- ){
                Node* node = q.front();
                q.pop();
                if ( node == NULL ) continue;
                node->next = tmp;
                tmp = node;
                q.push(node->right);
                q.push(node->left);

            }
        }
        return root;
    }
};  
```