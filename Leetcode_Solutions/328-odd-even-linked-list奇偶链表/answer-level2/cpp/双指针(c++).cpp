利用两个指针，第一个指针odd连接奇数位结点，第二个指针even连接偶数位结点，如图所示：
![奇偶链表.png](https://pic.leetcode-cn.com/d959054afd256bac67870fe118bbac0184bfe326483b65b30e8c77a48c59328d.png)

#### 注意
1. 在循环开始之前，应用一个变量记录偶数位开始的地方，不可在循环结束后将odd的next指向head->next,
因为这时的head->next已经指向了第二个奇数位；
2.在遍历过程中，由于even在odd的后面，所以当even为空指针时，odd已经将所有的奇数位结点全都找到，应结束循环。

```
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        auto even = head->next;
        auto odd = head;
        auto tmp = head->next;
        while(even && even->next && odd->next)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = tmp;
        return head;
        
    }
};
```