**头插法**：我们新建一个空的头结点来方便进行 头插
1. 每次从链表上取下结点，插入头结点下
2. 注意点：插入前，要先用临时的指针存储下当前结点，并移动结点，否则会因为将当前结点插入时，出现断链的情况
```
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *root=new ListNode(0),*cur = head;
        
        while(cur != NULL){
            ListNode *node = cur;
            cur = cur->next;
            node->next = root->next;
            root->next = node;
            
        }
        return root->next;
    }
};
```
