
116的题解见 <https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/solution/cpp-yan-du-you-xian-sou-suo-qing-song-jie-jue-by-x/>

这是我解决116题的代码

![image.png](https://pic.leetcode-cn.com/d659b3505de6af87c98a7a2f2e3a4f3147e051a3b406bb881c7ffa206621e00c-image.png)

我们只需要在这个代码的基础修改加入左右子节点的条件

```cpp
                if ( node->right != NULL ) q.push(node->right);
                if ( node->left != NULL ) q.push(node->left);
```

就可以用在我们这道题目中，或者说下面这代码可以直接用在116上

```cpp
class Solution {
public:
    Node* connect(Node* root) {
        if ( root == NULL ) return root;

        queue<Node *> q;
        q.push(root);

        while ( ! q.empty() ) {
            int q_size = q.size();
            Node *tmp = NULL;
            while (q_size-- ){
                Node* node = q.front();
                q.pop();
                if (node == NULL ) continue;
                node->next = tmp;
                tmp = node;
                if ( node->right != NULL ) q.push(node->right);
                if ( node->left != NULL ) q.push(node->left);

            }
        }
        return root;
        
    }
};
```