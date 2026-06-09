### 解题思路
因为是单链表，故无法访问节点的前驱指针，所以只能用后面节点的数据去替换前面节点的数据，在删除掉最后一个节点，就相当于删除了要求删除的那个节点

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) 
{
    if(node->next == NULL)
    {
        node = NULL;
    }
    else
    {
        while(node->next->next)   //最后保证只剩下2个节点
        {
            struct ListNode* _cur = node->next;
            node->val = _cur->val;
            node = _cur;
        }
        node->val = node->next->val;  //交换最后两个节点的值
        node->next = NULL;    //让尾指NULL
    }  
}
```