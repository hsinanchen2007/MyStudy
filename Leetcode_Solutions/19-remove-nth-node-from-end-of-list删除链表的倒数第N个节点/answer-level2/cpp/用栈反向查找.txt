### 解题思路
1. 对链表来说倒数第n个首先想到是反转链表再正向查找这样相比较用栈做缓存来说较麻烦。用栈存储链表的指针，再出栈到倒数第n-1个，此时pop第n个，在将栈顶与n-1个指针相连。
2. 注意边界，可能栈中没有节点此时直接返回curr就可以

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
        if(head == NULL) return NULL;
        stack<ListNode*> tmp;
        ListNode* node = head;
        while(node != NULL){
            tmp.push(node);
            node = node->next;
        }
        ListNode* curr = NULL;
        while(!tmp.empty() && n >1){
            curr = tmp.top();
            tmp.pop();
            n--;
        }
        tmp.pop();

        if(tmp.empty()) return curr;
        tmp.top()->next = curr;
        return head;
        
        
    }
};
```