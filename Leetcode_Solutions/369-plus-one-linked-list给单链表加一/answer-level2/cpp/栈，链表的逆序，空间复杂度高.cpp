### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        stack<int> stk;
        while(head != NULL){
            stk.push(head->val);
            head = head->next;
        }
        int cur = 1;//表示进位数字，首次进位1，相当于个位加1
        int new_num = 0;
        ListNode* q = NULL;
        ListNode* p = NULL;
        int num = stk.top();
        while(!stk.empty()){
            int num = stk.top();
            stk.pop();
            new_num = (num+cur)%10;
            cur = (num+cur)/10;

            p = new ListNode(new_num);
            p->next = q;
            q = p;
        }
        if(cur!=0){//如果最高位也要进位，就再添加一个节点
            ListNode* m = new ListNode(cur);
            m->next = q;
            return m;
        } 
        return q;


    }
};
```