### 解题思路
递归法解题。设立哑节点处理只有一个节点的情况。
![TIM截图20200322114305.png](https://pic.leetcode-cn.com/1dd8ab6c43baa43b3bfd99021f35b8c02ab3c58af4f38707ae8cb3dad3deb1fb-TIM%E6%88%AA%E5%9B%BE20200322114305.png)

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * start = new ListNode(0);
        start->next = head;
        foo(start, n);
        return start->next;
    }

    int foo (ListNode* l, int n){
        if(l->next == NULL) return 1;
        int f = foo(l->next, n);
        if(f == n) l->next = l->next->next;
        return f+1;
        }
    }
};
```