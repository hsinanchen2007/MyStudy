### 解题思路
反转链表的加强版，和前一个版本相比，相当于
1. 将链表分为3个部分，2个不反转部分和1个反转的部分
2. 前面的不反转部分，保留最后一个节点，后面的不反转部分，保留第一个节点
3. 对于反转部分，要保留两个端点
4. 反转结束后，将三个部分拼接起来

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n) return head;
        int len = n-m+1;
        //cout << "len: " << len << endl;
        ListNode* res = new ListNode(-1);
        res->next = head;

        // get the 1st part 
        ListNode* point_pre = new ListNode(-1);
        point_pre->next = head;
        for(int i = 1; i < m; ++i){
            head = head->next;
            point_pre = point_pre->next;
        }
        //cout << "point_pre->val: " << point_pre->val << " , head->val: " << head->val << endl;

        //get the 2nd part
        ListNode* pre = new ListNode(-1);
        ListNode* cur = new ListNode(-1);
        ListNode* post = new ListNode(-1);
        pre->next = head;
        cur = head;
        for(int i = 0; i < len; ++i){
            //cout << "pre: " << pre->val << ", cur: " << cur->val << endl;
            if(cur->next){
                post = cur->next;
                cur->next = pre;
                // change loop condition
                pre = cur;
                cur = post;
            }else{
                cur->next = pre;
                pre = cur;
                cur = NULL;
            }
        }
        //cout << "pre: " << pre->val << ", cur: " << cur->val << endl;
        point_pre->next = pre;

        //get the 3rd part
        head->next = cur;
        if(m == 1) return point_pre->next;
        else return res->next;
    }
};
```


### 结果
执行用时 : 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户 
内存消耗 : 6.5 MB , 在所有 C++ 提交中击败了 100.00% 的用户