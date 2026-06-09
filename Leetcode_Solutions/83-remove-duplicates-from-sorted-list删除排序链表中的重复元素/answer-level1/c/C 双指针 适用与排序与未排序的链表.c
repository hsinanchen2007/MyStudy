### 解题思路
本题链表是已经排序的，若题目未排序，则可以通过双指针循环解决

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode *p,*q,*temp;
    p = head;  //将p指向头节点 
    while(p != NULL) 
    {
        q = p;
        while(q->next != NULL) // q遍历p后面的结点，并与p数值比较
        {
            if(q->next->val == p->val)
            {
                temp = q->next; // temp保存需要删掉的结点
                q->next = temp->next;   // 需要删掉的结点的前后结点相接
                free(temp);
            }
            else
                q = q->next;
        }
        p = p->next;
    }
    return head;
}

```