### 解题思路
比较简单但时间复杂度比较高的算法：
设置三个指针，其中一个是临时指针tmp，用来充当被删除节点的上一个节点，设p1指针为头节点，p2为用来比较节点（即是否删除的节点），初始化为p1->next,如果两个头结点元素相等，删除p2，并使tmp = p2，即让p2和tmp同步向后移动，直到p2位空，让p1指向下一个节点，同时tmp=p1，p2=p1->next,这是第一轮比较；然后判断p1是否为空，重复第一轮,直到p1为空
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
    ListNode* removeDuplicateNodes(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* p1 = head;
        ListNode* p2 = NULL;
        ListNode* tmp = NULL;
        while(p1 != NULL)
        {
            tmp = p1;
            p2 = p1->next;
            while(p2 != NULL)
            {
                if(p1->val == p2->val)
                {
                    tmp->next = p2->next;
                }
                else
                {
                    tmp = p2;
                }
                p2 = tmp->next;
            }
            p1 = p1->next;
        }
        return head;
    }
};
```