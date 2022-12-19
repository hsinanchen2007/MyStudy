### 解题思路
这里传入的是删除节点的val值，须先找到该节点。原书传入的是节点类型，省去了查找节点的过程，更加简单的o(1)，与主站https://leetcode-cn.com/problems/delete-node-in-a-linked-list/类似

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
    ListNode* deleteNode(ListNode* head, int val) {
        if(head==NULL) return NULL;    
        if(head->val==val && head->next==NULL) return NULL; //链表只有头节点且为删除的节点
        if(head->val==val) return head->next;               //链表头节点为需删除的节点

        ListNode* tmp = head;
        while(tmp->next)
        {
            if(tmp->next->val==val && tmp->next->next)
            {
                tmp->next = tmp->next->next;
                break;
            }
            if(tmp->next->val==val && tmp->next->next==NULL)  //删除的节点为尾节点
            {
                tmp->next = NULL;
                break;
            }
            tmp = tmp->next;                  //链表中不存在要删除的节点，返回原链表
        }
        return head;   
    }
};
```