### 解题思路
此处撰写解题思路

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* swap = head;
        ListNode* t = head;
        int cnt = 0;
        while(swap){
            swap = swap->next;
            cnt++;
        }
        //当删除的是第一个元素时 直接不要第一个 返回head
        if(cnt == n){
            head = head->next;
            return head;
        }   
        //当删除的不是第一个元素时 先利用循环把中间的删除掉，然后返回之前保存的t
        int i = 1;
        while(i != cnt-n){
            head = head->next;
            i++;
        }
        head->next = head->next->next;
        return t;
    }
};
```