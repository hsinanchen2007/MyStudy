大概就是那几种做法：

- 反转链表：迭代法反转链表，比较简单。

```c++
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        ListNode *slow = nullptr, *fast = head;
        while(fast != nullptr) {
            ListNode *p = fast->next;
            fast->next = slow;
            slow = fast;
            fast = p;
        }      
        while(slow != nullptr) {
            res.push_back(slow->val);
            slow = slow->next;
        }  
        return res;
    }
};
```

- 头插法：创建一个新的链表，使用头插法添加元素，获得一个反转的链表。

```c++
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        ListNode *newHead = new ListNode(-1);
        while(head != nullptr) {
            ListNode *p = head->next;
            head->next = newHead->next;
            newHead->next = head;
            head = p;
        }
        head = newHead->next;
        while(head != nullptr) {
            res.push_back(head->val);
            head = head->next;
        }
        return res;
    }
};
```

- 使用栈：

```c++
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        stack<int> st;
        while(head != nullptr) {
            st.push(head->val);
            head = head->next;
        }
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
```

似乎是头插法和栈快一点，都是 0ms；反转实属 8 太行，要 4ms。