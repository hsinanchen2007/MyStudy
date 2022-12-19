### 思路
1. 若head为nullptr，返回nullptr
2. 若头节点的值与val相等，将头节点向后移一个位置
3. 赋值prev节点和cur节点，判断cur节点的值是否与val相等，若是，将cur节点删除
- 删除方法，将prev节点的指针指向cur的下一个节点，这样，cur的值就无法被访问，等同于删除。
```
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return nullptr;
        while(head -> val == val){
            head = head -> next;
            if(!head)   return nullptr;
        }
        ListNode* prev = head;
        ListNode* cur = head -> next;
        while(cur){
            if(cur -> val == val){
                prev -> next = cur -> next;
                cur = prev -> next;
            }
            else{
                prev = cur;
                cur = cur -> next;
            }
        }
        return head;
    }
};
```