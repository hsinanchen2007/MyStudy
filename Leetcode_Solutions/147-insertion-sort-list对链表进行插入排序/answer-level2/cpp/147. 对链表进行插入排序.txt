### 解题思路
istNode dummy(0);
        dummy.next=head;
auto t=&dummy;//不要是dummy.next,因为拿下一个节点t->next->val的值比较


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
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode dummy(0);
        dummy.next=head;
        auto pre=head;
        auto node=head->next;
        while(node){
            if(node->val<pre->val){
                auto t=&dummy;//不要是dummy.next,因为拿下一个节点t->next->val的值比较
                while(t->next->val<node->val){
                    t=t->next;
                }//找到插入点的前一个节点，所以用t->text->val
                pre->next=node->next;//从后往前，连接节点
                node->next=t->next;
                t->next=node;
                node=pre->next;
            }
            else{
                pre=pre->next;
                node=node->next;
            }
        }
        return dummy.next;
    }
};
```