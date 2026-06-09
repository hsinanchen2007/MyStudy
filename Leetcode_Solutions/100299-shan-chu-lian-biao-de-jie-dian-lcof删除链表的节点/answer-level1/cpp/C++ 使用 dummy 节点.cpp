### 思路
构建头部 dummy 节点，后面的操作就可以转化为一般化得链表节点移除问题

### 代码
```cpp
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* prev = dummy;
        while(prev && prev -> next) {
            if(prev -> next -> val == val) {
                prev -> next = prev -> next -> next;
                break;
            }
            prev = prev -> next;
        }
        return dummy -> next;
    }
};
```