使用一个哑结点p作为针线，串接起l1和l2。
![image.png](https://pic.leetcode-cn.com/3cf385b59ee23e35ac0588c67ab4c021bb9fad0a92dd8cc7070011428e7d240c-image.png)

```c++[]
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = nullptr;
        ListNode *p = nullptr;
        if(l1 == NULL){
            return l2;
        }else if(l2 == NULL){
            return l1;
        }else{
            res = (l1->val <= l2->val)? l1: l2;
        }
        
        p = res;
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                l1 = l1->next;
                if(l1 != NULL && l1->val <= l2->val){
                    p->next = l1;
                }else{
                    p->next = l2;
                }
                p = p->next;
            }else{
                l2 = l2->next;
                if(l2 != NULL && l2->val < l1->val){
                    p->next = l2;
                }else{
                    p->next = l1;
                }
                p = p->next;
            }
        }
        return res;
    }
};
```

执行用时 :12 ms, 在所有 C++ 提交中击败了86.51%的用户
内存消耗 :8.7 MB, 在所有 C++ 提交中击败了98.58%的用户