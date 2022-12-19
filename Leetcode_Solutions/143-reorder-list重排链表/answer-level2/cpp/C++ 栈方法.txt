### 解题思路
思路已经在代码注释中

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
 /*栈方法*/
class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> s;
        ListNode* p = head;
        while(p) {          //进行入栈, 利用栈先入后出的特性
            s.push(p);
            p = p->next;
        }
        if(s.size() <= 2) { //<=2的结点数直接返回 因为符合题意
            return;
        }

        p = head;
        int size = s.size();
        for(int i = 0; i < size / 2; i++) { //进行一半出栈 一半遍历的过程
            ListNode* next = p->next;
            p->next = s.top();
            s.pop();
            p->next->next = next;
            p = next;
        }
        p->next = NULL;
        return;
    }
};

```
![image.png](https://pic.leetcode-cn.com/4dcd6a2a465a996e8785ed1c8bb48fd258a631e1217ef7428e4ddd86792d1fbf-image.png)
