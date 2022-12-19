### 解题思路
采用快慢指针：
慢指针指向被删除结点；再用一个临时指针记录被删除结点前一个结点位置；

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
        // 双指针; pre指向要删除结点
        // tail指向尾结点next地址
        ListNode *pre = head, *tail = head;
        ListNode *temp=pre;    //需要释放的结点的前一个结点
        // 步长n
        for(int i=0; i<n; ++i){
            tail = tail->next;
        }
        while(tail!=NULL){
            temp = pre;
            pre = pre->next;
            tail = tail->next;
        }
        if(pre==head){
            head = head->next;
        }else{
            temp->next = temp->next->next;
        }
        delete pre;

        return head;
    }
};
```