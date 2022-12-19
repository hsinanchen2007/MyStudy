### 解题思路
- 非常清楚的是，一个长度为`n`的链表，向右移`n`个位置之后，和原来相同。所以对于给定`k`，我们只要右移`k%n`即可
- 右移和左移可以通过翻转(逆置)完成
- 给定输入`[1,2,3,4,5]`，`k = 2`,将`[1,2,3,4,5]`看成两部分`[1,2,3]`和`[4,5]`组成，后半部分的长度为k
- 分别翻转得到`[3,2,1]`和`[5,4]`
- 组合后为`[3,2,1,5,4]`，再将`[3,2,1,5,4]`全局翻转得到`[4,5,1,2,3]`即为所求



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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        ListNode *p = head;
        int len = 0;
        while(p){
            len ++;
            p = p->next;
        }
        ListNode *res = new ListNode(0);
        res->next = head;
        ListNode *slow = res, *fast = res;
        k = k % len;
        while(k>=0){
            fast = fast->next;
            k--;
        }
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }
        //链表分为两部分
        ListNode *p2 = slow->next;
        slow->next = NULL;

        // 翻转 p1
        ListNode *pre = NULL;
        ListNode *_next, *p1 = head;
        while(p1){
            _next = p1->next;
            p1->next = pre;
            pre = p1;
            p1 = _next;
        }
        p1 = pre;

        // 翻转p2
        pre = NULL;
        while(p2){
            _next = p2->next;
            p2->next = pre;
            pre = p2;
            p2 = _next;
        }
        p2 = pre;
        // 连接p1与p2，链头为p1
        head->next = p2;
        
        //翻转p1
        pre = NULL;
        while(p1){
            _next = p1->next;
            p1->next = pre;
            pre = p1;
            p1 = _next;
        }
        return pre;
    }
};
```