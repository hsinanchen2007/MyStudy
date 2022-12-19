### 解题思路
此处撰写解题思路
![QQ截图20200320134731.jpg](https://pic.leetcode-cn.com/f1f1de3c3442019d4eee2ad36ddd7e7f090ecf67e40c6609b4687a6d5a1a52ba-QQ%E6%88%AA%E5%9B%BE20200320134731.jpg)

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
    ListNode* partition(ListNode* head, int x) {
        ListNode *head_up = new ListNode(0);
        ListNode *head_down = new ListNode(0);
        ListNode *up = head_up;
        ListNode *down = head_down;
        ListNode *tem = up;
        while(head){
            if(head->val >= x){
                up->next = head;
                up = up->next;
            }
            else{
                down->next = head;
                down = down->next;
            }
            head = head->next;
        }
        down->next = tem->next;
        up->next = NULL;
        return head_down->next;
    }
};
```