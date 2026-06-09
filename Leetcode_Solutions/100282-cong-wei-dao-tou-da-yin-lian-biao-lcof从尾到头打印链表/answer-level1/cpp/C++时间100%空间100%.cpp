先全压进栈，再把vector前后倒过来
```
#include<algorithm>
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        ListNode *p;
        vector<int> res;
        for(p=head; p; p=p->next)
            res.push_back(p->val);
        int length = res.size();
        for(int i=0; i<length/2; i++)
            swap(res[i],res[length-1-i]);
        return res;
    }
};
```
