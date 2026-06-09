### 解题思路
采用链表的前插法进行链表的构建

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
    ListNode* reverseList(ListNode* head) {
        ListNode* current = nullptr;
        if(head){  //要判断初始链表是否为空
            ListNode* n = nullptr;
            current = new ListNode(head->val); //初始化当前节点(即预先构造一个节点)
            n = head->next;  //下一个要插入的节点
            while(n){
                ListNode* tmp = new ListNode(n->val);  //新建一个节点
                tmp->next = current;
                current = tmp;
                n = n->next;
            }
            return current;
        }
        return current;
    }
};
```