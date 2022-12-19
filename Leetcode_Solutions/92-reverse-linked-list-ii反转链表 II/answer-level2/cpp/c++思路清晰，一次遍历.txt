### 解题思路
1. 创建一个新链表，两个指针；
2. m之前正常插入；
3. m和n之间，将head从头结点一个一个从newhead的m的位置插入；
4. n之后，直接将head拼接在后面
（事件复杂度不理想，不知道为什么遍历一次的时间复杂度会略微差）
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n) return head;
        ListNode *newhead = new ListNode(0);
        ListNode *p1 = newhead;
        ListNode *p2 = NULL;
        int start = 1;
        int end = 1;
        while(head){
            if(start < m){
                p1->next = head;
                head = head->next;
                p1 = p1->next;
                start++;
                end++;
            }else if(start >= m && end <= n){
                p1->next = head;
                head = head->next;
                p1->next->next = p2;
                p2 = p1->next;
                end++;
            }else if(end > n){
                while(p2->next) p2 = p2->next;
                p2->next = head;
                break;
            }
        }
        return newhead->next;
    }
};
```