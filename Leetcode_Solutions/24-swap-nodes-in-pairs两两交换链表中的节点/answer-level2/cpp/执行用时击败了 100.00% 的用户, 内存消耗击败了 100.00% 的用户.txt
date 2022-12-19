### 解题思路
这道题目一定要知道的是，当你在进行链表某一个节点替换的，你涉及到的是3个节点，目标节点，指向目标节点的节点，以及目标节点指向的节点。
这道题目交换相邻的节点，那么会涉及到四个节点。
我这里使用了pre, cur, post(实际上还有post->next)进行节点替换。多定义一些临时linkNode，少用多个next，这样思路会更清晰

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
        ListNode* res = new ListNode(-1);
        res->next = head;
        ListNode* head_next = new ListNode(-1);
        head_next = head->next;
        //swap start node of linklist
        res->next = head_next;
        head->next = head_next->next;
        head_next->next = head;
        while(head->next){
            ListNode* pre = new ListNode(-1);
            ListNode* cur = new ListNode(-1);
            ListNode* post = new ListNode(-1);
            pre = head;
            if(head->next){
                cur = head->next;
            }else{
                return res->next;
            }
            if(cur->next){
                post = cur->next;
            }else{
                return res->next;
            }
            //swap node
            cur->next = post->next;
            post->next = cur;
            pre->next = post;
            head = cur;
        }
        return res->next;
    }
};
```

### 结果
执行用时 : 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户
内存消耗 : 6.2 MB , 在所有 C++ 提交中击败了 100.00% 的用户