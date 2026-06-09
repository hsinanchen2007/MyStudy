![WechatIMG1582.jpeg](https://pic.leetcode-cn.com/d972ce28423f3f1bf54381c8e3cb2322895918f226ee35008bfdec5a6f93e637-WechatIMG1582.jpeg)
```
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len = listLen(root);
        
        int num = len / k;
        int res = len % k;
        int sec = 0;
        ListNode* cur = root;

        vector<ListNode*> out(k, NULL);
        for(int i = 0; i < k; i++){
            sec = res > i ? num + 1 : num;
        
            if(sec > 0){
                out[i] = cur;
                while(sec > 1){
                    sec--;
                    cur = cur -> next;
                }
            
                ListNode* tmp = cur -> next;
                cur -> next = NULL;
                cur = tmp;
            }
        }

        return out;
    }

    int listLen(ListNode* root){
        ListNode* cur = root;
        int len = 0;
        while(cur != NULL){
            len++;
            cur = cur -> next;
        }
        return len;
    }
};
```

