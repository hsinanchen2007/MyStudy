### 解题思路
经典递归解法：把当前头节点的下一个节点当作新链表的头节点输入
1. 判定头节点是否为空；
2. 声明一个新节点revhead，初始化为head的next；
3. 递归逆序处理以revhead开头的新链表；
4. 把head节点赋值revhead的next；
5. 把head的next节点赋空；
6. 返回反转后的头节点revhead。

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
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode* revhead=head->next;
        ListNode* revnode=reverseList(revhead);
        revhead->next=head;
        head->next=nullptr;
        return revnode;

    }
};
```