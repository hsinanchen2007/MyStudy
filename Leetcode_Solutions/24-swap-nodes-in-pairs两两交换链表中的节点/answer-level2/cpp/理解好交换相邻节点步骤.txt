### 解题思路
单链表包含头结点和剩余节点，其中头结点不包含值。注意在进行交换的时候判断当前节点的下一个节点是否为空。
交换两个节点要经过3个步骤：
用tmp,p1,p2分别表示当前节点的前一个节点，当前节点和当前节点的下一个节点
1、先找到p2的前驱，即tmp->next = p2
2、再找到p1的后继，即p1->next = p2->next
3、最后找到p1的前驱，即p2->next = p1
剩下的就是判断交换后的节点的下一个节点和下下个节点是否为空，如果都不为空，继续交换。

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* p1 = head;
        ListNode* p2 = p1->next;
        ListNode* p3 = NULL;
        //交换前两个节点
        p1->next = p2->next;
        p2->next = p1;
        head = p2;
        while(p1->next != NULL)
        {
            p3 = p1;
            p1 = p1->next;
            if (p1->next == NULL)
                break;
            p2 = p1->next;
            p3->next = p2;
            p1->next = p2->next;
            p2->next = p1;
        }
        return head;
    }
};
```