**要点**
1. 利用哈希表构造map<listnode*, int>；
2. 在一次链表遍历后保存每个listnode；
3. 根据当前节点的后续节点是否在map中来判断是否有环；
```
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, int> map;
        while(head){
            if(map.find(head)==map.end()) map[head]=1;
            if(map.find(head->next)!=map.end()) return true;
            head = head->next;
        }
        return false;
    }
};
```
