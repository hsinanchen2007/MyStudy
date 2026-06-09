### 解题思路
此处撰写解题思路

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
        //遍历链表，如果找到这个数，将后面节点的数复制到这个节点上，然后删除后面那个节点
        bool symbol = false;
        ListNode *root = head;
        while(head->next->next!=NULL){
            if(head->val == val){
                head->val = head->next->val;
                head->next = head->next->next;
                symbol = true;
                break;
            }else{
                head = head->next;
            }
        }
        //链表删除节点在最后的两个节点.
        if(head->val == val && symbol == false){
            head->val = head->next->val;
            head->next = NULL;
        }else if(symbol == false){
            head->next = NULL;
        }
        return root;
    }
};
```