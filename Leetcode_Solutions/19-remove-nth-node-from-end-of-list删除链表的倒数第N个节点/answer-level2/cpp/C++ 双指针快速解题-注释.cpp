### 解题思路
![题解19.PNG](https://pic.leetcode-cn.com/d900e29669e088ae73662caea21dfe95caf74e4a1072509759972aa0fd1bf02a-%E9%A2%98%E8%A7%A319.PNG)

使用双指针法。
front节点和rear节点之间有n 个节点，并同时向后移动。当rear为NULL时停止窗口移动，并删除front->next节点。
时间复杂度为O(n)。

### 代码

```
class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* front = head;
        ListNode* rear = head;
        if(head->next == NULL) return NULL;
        while(n-- >= 0){
            if(rear == NULL) return head -> next;
            rear = rear->next;
            // n --;
        }
        while(rear){
            rear = rear -> next;
            front = front -> next;
        }
        front->next = front->next->next;
        return head;
    }
};
```