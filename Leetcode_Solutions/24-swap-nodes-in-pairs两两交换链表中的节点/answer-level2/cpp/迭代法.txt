### 解题思路
说明：
head指向当前结点
head_next指向当前结点的下一个结点
pre用来保存head的前驱

步骤：
1.判断当前结点与后继结点是否为空
2.不为空，则交换head与head_next
3.pre指向交换后的结点（head_next）
4.修改pre为下一次循环的前驱（即当前的head结点）
5.head指向下一个结点，再次执行12345，直至为空

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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;

        ListNode* prehead = new ListNode(-1);
        ListNode* head_next = new ListNode(-1);
        prehead->next = head;

        ListNode* pre = new ListNode(-1);
        pre = prehead;
        while(head != NULL)
        {
            head_next = head->next;
            if(head_next != NULL)
            {
                head->next = head_next->next;
                head_next->next = head;
                pre->next = head_next;
               
            }
            pre = head;
            head = head->next;
        }
        return prehead->next;
    }
};
```