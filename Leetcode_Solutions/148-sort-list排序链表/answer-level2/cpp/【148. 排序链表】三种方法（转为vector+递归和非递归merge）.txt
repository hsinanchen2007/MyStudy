## 思路一：利用vector
### 代码
```c++
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        vector<int> res;
        ListNode *cur = head;
        while (cur) {
            res.push_back(cur->val);
            cur = cur->next;
        }
        sort(res.begin(), res.end());
        cur = head;
        int i = 0;
        while (cur) {
            cur->val = res[i];
            cur = cur->next;
            ++i;
        }
        return head;
    }
};
```

## 思路二：归并排序
利用递归
### 代码
```c++
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *f = head, *s = head, *pre = head;
        while (f != nullptr && f->next != nullptr) {
            pre = s;
            s = s->next;
            f = f->next->next;
        }
        pre->next = nullptr;
        return merge(sortList(head), sortList(s));
    }
    
    ListNode *merge(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        if (l1->val < l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }        
    }
};
```
#### 非递归
```c++
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *f = head, *s = head, *pre = head;
        while (f != nullptr && f->next != nullptr) {
            pre = s;
            s = s->next;
            f = f->next->next;
        }
        pre->next = nullptr;
        return merge(sortList(head), sortList(s));
    }
    
    ListNode *merge(ListNode *l1, ListNode *l2) {        
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        ListNode *pHead = new ListNode(-1);
        ListNode *cur = pHead;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {            
                cur->next = l1;
                l1 = l1->next;            
            } else {
                cur->next = l2;
                l2 = l2->next;            
            }   
            cur = cur->next;
        }       
        if (l1) {
            cur->next = l1;
        }
        if (l2) {
            cur->next = l2;
        }
        return pHead->next;
    }
};
```

