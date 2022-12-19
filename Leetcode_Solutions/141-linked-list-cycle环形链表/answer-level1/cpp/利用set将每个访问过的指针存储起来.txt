若访问的指针已经在set中了，则说明有环。
若有环则必定会访问到重复的指针，若没环则必定会访问到空指针，这时结束对指针的访问。
```C++ []
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        while(head){
            if(!s.insert(head).second){
                return true;
            }
            head=head->next;
        }
        return false;
    }
};
```
