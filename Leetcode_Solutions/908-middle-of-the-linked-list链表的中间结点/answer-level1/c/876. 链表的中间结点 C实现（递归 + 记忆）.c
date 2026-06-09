### 解题思路
    想用递归实现所以没用循环和快慢指针一样双百，递归至表尾，记录size，cnt =（size + 1） / 2 可以得到中间点的位置，递归返回时依次自减，cnt减为0时表示到达中间位置，记录该节点作为返回值。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode node;

void Recurse(node* n, int* cnt,int* size, node** res)
{
    if (!n) {
        *size = *cnt;
        (*cnt)++;
        *cnt /= 2;
        return;
    }
    (*cnt)++;
    Recurse(n->next, cnt, size, res);
    (*cnt)--;
    if (*cnt == 0) {
        *res = n;
    }
    return;
}

struct ListNode* middleNode(struct ListNode* head){
    if (!head) {
        return head;
    }
    int cnt = 0;
    int size = 0;
    node* res = NULL;
    Recurse(head, &cnt, &size, &res);
    return res;
}
```