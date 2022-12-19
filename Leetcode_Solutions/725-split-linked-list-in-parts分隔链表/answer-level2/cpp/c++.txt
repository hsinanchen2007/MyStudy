```
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode *p = root;
        int len = 0;
        vector<ListNode*> v;

        while (p){
            p = p -> next;
            len++;
        }
        if (len <= k){
            p = root;
            ListNode *t;
            while (p){
                v.push_back(p);
                t = p -> next;
                p -> next = nullptr;
                p = t;
                k--;
            }
            while (k--){
                v.push_back(nullptr);
            }
        }
        else{
            int cnt = len / k;
            int add = len % k;
            int inter;
            ListNode *t;

            p = root;
            while (k--){
                inter = add-- > 0 ? cnt + 1 : cnt;
                v.push_back(p);
                while (--inter){
                    p = p -> next;
                }
                t = p -> next;
                p -> next = nullptr;
                p = t;
            }
        }
        return v;
    }
};
```
