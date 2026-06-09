### 解题思路
递归与迭代

### 代码

#### 递归
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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        recur(head);
        head->next = NULL;
        return head2;
    }
    void recur(ListNode* p){
        if(p->next->next != NULL) recur(p->next);
        else head2 = p->next;
        p->next->next = p;
        return;
    }
private:
    ListNode* head2;
};
```

#### 迭代

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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
            ListNode* p1 = NULL;
            ListNode* p2;
        while(head != NULL){
            p2 = head->next;
            head->next = p1;
            p1 = head;
            head = p2;
        }
        return p1;
    }
};
```