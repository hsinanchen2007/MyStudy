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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k==0) return head;
        ListNode * end = head;
        ListNode * curpos = head;
        int num = 1;                //记录链表结点的个数
        while(end->next != NULL) {
            end=end->next;          //找到链表尾部
            num++;                  //统计结点的个数
        }
        end->next = head;
        int pos = num - k % num - 1;//找到断开的位置
        while(pos>0){
           curpos = curpos->next;
           pos--;
        }
        head=curpos->next;
        curpos->next=NULL;
        return head;
    }
};
```