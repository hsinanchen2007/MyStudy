### 解题思路

**链表最关键的就是不能断链**
temp->p->q->next
temp->next = q
p->next = q->next
q->next = p
temp->q->p->next(p->next = q->next 故没有断链)

### 递归(0ms, 7.5MB)
每次交换两个结点。把第二个结点的后续结点作为新的头节点进行递归
递归结束条件: 无需交换
```cpp
if(head == NULL || head->next == NULL) return head; // 无需交换
        ListNode* p = head->next;
        ListNode* q = p->next;
        p -> next = head;
        head->next = swapPairs(q);
        return p;
```

### 迭代(4ms, 8MB)
交换完以后
temp = p
p = p->next
q = p->next
这个更新要注意为空值具体代码看下方
```cpp
ListNode* rst = new ListNode(-1); //指向头结点
        rst->next = head;
        ListNode* p = rst; // 前驱结点
        if(head != NULL) {
            ListNode* q = head->next;
            while (head != NULL && head->next != NULL){
                q = head->next; // head->next
                p->next = q;
                head->next = q->next;
                q->next = head; // 关键是不能断链
                p = head;
                head = head->next;
            }
        }
        return rst->next;
```
### 直接交换值(0ms, 7.5MB)
```cpp
ListNode* rst = head;
        ListNode* temp = head;
        while (!(temp == NULL||temp->next == NULL)){
            temp->val += temp->next->val;
            temp->next->val = temp->val - temp->next->val;
            temp->val -= temp->next->val;
            temp = temp->next->next; 
        }
        return rst;
```
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
        // 将head和head->next交换
        // 递归调用head->next->next
        // head p = head->next q = head->next->next
        // p->next = head;
        // head->next= swapPairs(q);
        // return q;
        // 递归
        /*
        if(head == NULL || head->next == NULL) return head; // 无需交换
        ListNode* p = head->next;
        ListNode* q = p->next;
        p -> next = head;
        head->next = swapPairs(q);
        return p;*/
        // 直接交换值
        /*
        ListNode* rst = head;
        ListNode* temp = head;
        while (!(temp == NULL||temp->next == NULL)){
            temp->val += temp->next->val;
            temp->next->val = temp->val - temp->next->val;
            temp->val -= temp->next->val;
            temp = temp->next->next; 
        }
        return rst;
        */
        // 迭代
        ListNode* rst = new ListNode(-1); //指向头结点
        rst->next = head;
        ListNode* p = rst; // 前驱结点
        if(head != NULL) {
            ListNode* q = head->next;
            while (head != NULL && head->next != NULL){
                q = head->next; // head->next
                p->next = q;
                head->next = q->next;
                q->next = head; // 关键是不能断链
                p = head;
                head = head->next;
            }
        }
        return rst->next;
    }
};
```