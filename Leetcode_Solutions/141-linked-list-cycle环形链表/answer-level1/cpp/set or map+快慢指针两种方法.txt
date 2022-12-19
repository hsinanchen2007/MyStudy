```
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 方法二 快慢指针
        if(head==NULL||head->next==NULL) return false;
        ListNode *st=head;
        ListNode *ed=head->next;
        while(st!=ed){
            if(ed==NULL||ed->next==NULL) return false;
            st=st->next;
            ed=ed->next->next;
        }
        return true;
        // 方法一 set or map
        // unordered_set<ListNode *> st;
        // while(head!=NULL){
        //     if(st.count(head)) return true;
        //     st.insert(head);
        //     head= head->next;
        // }   
        // return false; 

        // unordered_map<ListNode *,int> mp;
        // while(head!=NULL){ 
        //     if(mp[head]==2) return true;
        //     mp[head]++;
        //     head= head->next;
        // }   
        // return false;
    }
};
```
