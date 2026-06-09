### 解题思路
采用双指针的思想，第，一个指针p先向后移动k个节点，这时第二个指针q从头节点开始与第二个指针同时向后移动，当地一个指针到达末尾时，第一个指针正好到达倒数第k个节点。

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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int ck = k;

        ListNode* p = head;
        while(ck){
            // 指针p先向后移动k个长度
            if(p){
                p = p->next;
                --ck;
            }
            else{
                // 链表长度小于k
                return nullptr;
            }
        }

        ListNode* q = head;
        while(p){
            // 因为p比q快k个位置，所以当p到达末尾时，q正好是倒数第k个节点
            p = p->next;
            q = q->next;
        }

        return q;
    }
};
```