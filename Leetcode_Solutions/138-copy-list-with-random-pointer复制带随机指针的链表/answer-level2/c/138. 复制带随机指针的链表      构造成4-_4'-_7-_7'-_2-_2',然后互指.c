### 解题思路
参考官方题解3，好思想。



给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的 深拷贝。 

我们用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：

val：一个表示 Node.val 的整数。
random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
 

示例 1：



输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]

### 代码

```c
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct TreeNode *next;
 *     struct TreeNode *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
    struct Node* l = head, * temp;
    while (l) {
        temp = l->next;
        l->next = malloc(sizeof(struct Node));
        l->next->val = l->val;
        l->next->random = NULL;
        l->next->next = temp;
        l = temp;
    }

    l = head;
    struct Node* newhead = l ? l->next : NULL;
    while (l) {
        l->next->random = l->random ? l->random->next: NULL;
        temp = l->next->next;
        l->next->next = temp ? temp->next : NULL;
        l = temp;
    }

    return  newhead;
}
```