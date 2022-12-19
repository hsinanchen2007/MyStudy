
```
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        map<int,int> myMap;
        ListNode* p = head;
        while(p!=NULL){
            myMap[p->val]++;  //保存链表中每个节点值出现的次数
            p = p->next;
        }
        p = head;
        map<int,int>::iterator iter = myMap.begin();
        while(iter!=myMap.end()){  //遍历map
            for(int i = 0;i<iter->second;i++){
                p->val = iter->first;
                p = p->next;
            }
            iter++;
        }
        return head;
    }
};
```
