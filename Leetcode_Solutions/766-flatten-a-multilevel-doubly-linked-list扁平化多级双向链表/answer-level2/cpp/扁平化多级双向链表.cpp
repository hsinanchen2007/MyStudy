### 算法分析
1. 使用二叉树深度优先搜索，将child节点看作left节点，next节点看作right节点
2. 采用递归方式，先递归遍历左子树，再递归遍历右子树
3. 返回head节点
### 复杂度分析
+ 时间复杂度：O(n)
+ 空间复杂度：O(n)
### 源码
```C++ []
class Solution {
public:
    Node* flattenRecusive(Node* head)
    {
        if (head == NULL)
            return NULL;

        Node* nextNode = head->next;
        Node* childNode = head->child;

        if (nextNode == NULL && childNode == NULL)
        {
            return head;
        }

        Node* node = flattenRecusive(childNode);

        if (node != NULL)
        {
            head->next = childNode;
            childNode->prev = head;
            node->next = nextNode;
            if (nextNode != NULL)
                nextNode->prev = node;
            head->child = NULL;
        }

        return nextNode != NULL ? flattenRecusive(nextNode) : node;
    }

    Node* flatten(Node* head) {
        flattenRecusive(head);
        return head;
    }
};