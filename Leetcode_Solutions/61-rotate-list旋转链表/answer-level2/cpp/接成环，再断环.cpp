### 解题思路
把整个链表连接成环，之后找到需要切断的点把环再次切成链

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr)
        return nullptr;
        int n = 0;
        ListNode * t = head;
        ListNode *l;
        while(true){
            n++;
            if(t -> next == nullptr){
                t -> next = head;
                break;
            }
            t = t -> next;
        }
        k = k%n;
        k = n-k;
        l = t;
        t = head;
        while(k--){
            t = t -> next;
            l = l -> next;
        }
        l -> next = nullptr;
        return t;
    }
};
```