### 解题思路
此处撰写解题思路
1 参考了示例代码，使用了哨兵节点避免了处理头结点的问题。
2 使用递归，获得当前的倒数编号。
3 要处理倒数N， 必须在倒数N+1的节点，做断表处理
4 即便n不在列表内也可以照样处理。
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
        ListNode fack(0);
        fack.next = head;
        getRevid(&fack, n);
        return fack.next;
    }

    int getRevid( ListNode* h, int const n){
        if(h == NULL){
            return 0;
        }
        int rid = getRevid(h->next, n)+1;
        if(rid == n+1){
            h->next = h->next->next;
        }
        return rid ;
    }
};
```