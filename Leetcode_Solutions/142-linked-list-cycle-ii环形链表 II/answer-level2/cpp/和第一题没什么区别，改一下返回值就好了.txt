下面代码把head的位置改了，如果完全不改变链表的话，最好头结点另外赋给一个指针，用这个指针进行遍历访问。
当然了，看第一题官方题解有用双指针法的，这种方法再这题里就没那么好改了。
```C++ []
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        while(head){
            if(!s.insert(head).second){
                return head;
            }
            head=head->next;
        }
        return NULL;
    }
};
```
