### 解题思路
此处撰写解题思路

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
    ListNode* reverseList(ListNode* head) 
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *pre, *present, *follow;
        pre = head; //头结点
        present = pre->next;//第一个
        follow = present->next;//第二个

        present->next = pre; //翻转第一第二个结点
        pre->next = NULL;

        while (follow != NULL)
        {
            pre = present;
            present = follow;
            follow = follow->next; //后移

            present->next = pre;
        }
        return present;
    }
};
```如果结点数为空或者结点数为1，直接返回， 先翻转前两个结点，后面的结点采用三个指针pre, p, follow