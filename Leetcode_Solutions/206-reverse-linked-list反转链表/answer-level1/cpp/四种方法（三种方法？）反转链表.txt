### 解题思路
### 借助额外空间
### 采用头插法逐渐生成新链表
### 迭代就地反转
与头插法类似
### 递归
递归我不会，一会看下

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
    ListNode* reverseList(ListNode* head) {
        /*
        // 借助额外空间 2020 3 24 9:18
        ListNode* rst = new ListNode(-1);
        rst->next = head;
        ListNode *temp = rst->next;
        vector<int> supply;
        while(temp!= NULL){
            supply.push_back(temp->val);
            temp = temp->next;
        }// 走到底
        int i=0; int j = supply.size()-1;
        while(i<j){
            supply[i] += supply[j];
            supply[j] = supply[i] - supply[j];
            supply[i] -= supply[j];
            ++i;
            --j;
        } //数据反转
        temp = rst->next;
        i=0;
        while(temp != NULL){
            temp->val = supply[i++];
            temp = temp->next;
        } 
        return rst->next;
        */
        /*
        // 头插法 2020 3 24 9:21
        ListNode *rst = new ListNode(-1);
        ListNode *pro = head;
        while(head!=NULL){
            pro = head;
            head = head->next;
            pro->next = rst->next;
            rst->next = pro;
        }
        return rst->next;
        */
        ListNode* pre = NULL;
        ListNode *temp = head;
        while (head) {
            temp = head->next;
            head->next = pre;
            pre = head;
            head = temp;
        }
        return pre;
    }
};
```