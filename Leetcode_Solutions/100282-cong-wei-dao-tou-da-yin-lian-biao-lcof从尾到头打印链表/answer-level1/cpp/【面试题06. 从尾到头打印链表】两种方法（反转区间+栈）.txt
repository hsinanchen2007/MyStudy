## 思路一：反转数组

### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```cpp
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        if (!head) return res;
        while (head != nullptr) {
            res.push_back(head->val);
            head = head->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```

## 思路二：栈

### 代码
时间复杂度：O(n)
空间复杂度：O(n)
```c++
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        if (!head) return res;
        stack<int> st;
        while (head != nullptr) {
            st.push(head->val);
            head = head->next;
        }
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }        
        return res;
    }
};
```
