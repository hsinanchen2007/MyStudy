### 解题思路
- 可以采用dummy结点
- 也可以不采用dummy结点

### 代码

8ms 6.8MB
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* rst = new ListNode(-1);
        rst->next = head;
        ListNode *pro = rst;
        ListNode *circle_p = head;// 判断出现重复的数组
        int temp = 0;
        while(circle_p != NULL && circle_p->next != NULL){
            if(circle_p->val == circle_p->next->val){
                temp = circle_p->val;
                circle_p = circle_p->next;
                while(circle_p->val == temp) {
                    circle_p = circle_p->next;
                    if(circle_p == NULL){
                        pro->next = NULL;
                        return rst->next;
                    }
                }
                pro->next = circle_p;
                continue;
            }
            pro = pro->next;
            circle_p = circle_p->next;
        }
        return rst->next;
    }
};
```