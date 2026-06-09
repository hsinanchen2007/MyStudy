## 不添加头节点
**把第一个节点当成头节点，最后再处理**
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head;
        ListNode *pre=head;
        while(pre->next){
            if(pre->next->val==val)
                pre->next = pre->next->next;         
            else
                pre = pre->next;
        }
        if(head->val==val){
            head = head->next;
        }
        return head;
    }
};
```
## 添加虚拟头节点
**为了方便操作添加一个头节点，之后再删掉**
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *H = new ListNode(0);
        ListNode *pre=H;
        H->next = head;
        while(pre->next){
            if(pre->next->val==val)
                pre->next = pre->next->next;
            else
                pre = pre->next;
        }
        return H->next;
    }
};
```