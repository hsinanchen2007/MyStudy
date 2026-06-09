```
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int>num;
        ListNode* p = head;
        while(p){
            num.push_back(p->val);
            p = p->next;
        }
        sort(num.begin(), num.end());
        ListNode* q = head;
        int cnt = 0;
        while(q){
            q->val = num[cnt];
            cnt++;
            q = q->next;
        }
        return head;
    }
};
```
![1.png](https://pic.leetcode-cn.com/6a8a4c66ffcf0970ba7c762da538d15ef6ce87cefb061b8b992023fba49baf9c-1.png)
