方法一、
```
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        vector<int> vec;
        ListNode* res=l1;
        ListNode* rs=l1;
        while(l1!=NULL){
            vec.emplace_back(l1->val);
            l1=l1->next;
        }
        while(l2!=NULL){
            vec.emplace_back(l2->val);
            l2=l2->next;
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            if(res->next==NULL&&vec.size()-i>1) res->next=new ListNode(0);
            res->val=vec[i];
            res=res->next;
        }
        return  rs;
    }
};
```
