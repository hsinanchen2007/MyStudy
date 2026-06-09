```
class Solution {
public:
    ListNode* partition(ListNode* head, int x) 
    {
        vector<int> s1;
        vector<int> s2;
        ListNode* ptr=head;
        while(ptr!=NULL)
        {
            if(ptr->val<x) s1.push_back(ptr->val);
            else s2.push_back(ptr->val);
            ptr=ptr->next;
        }
        ptr=head;
        for(int i=0;i<s1.size();i++)
        {
            ptr->val=s1[i];
            ptr=ptr->next;
        }
        for(int j=0;j<s2.size();j++)
        {
            ptr->val=s2[j];
            ptr=ptr->next;
        }
        delete ptr;
        return head;
    }
};
```
