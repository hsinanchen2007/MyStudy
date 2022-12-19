### 解题思路
此处撰写解题思路
遍历两次链表，调用<cmath>文件的pow函数
a+=(h->val?pow(2,i):0);
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
 #include <cmath>
class Solution {
public:
    int getDecimalValue(ListNode* head) {
#if 1
        int a = 0;
        while(head!=nullptr){
            a = a*2 + head->val;
            head = head->next;
        }
        return a;
#else
        if(!head)
            return 0;
        ListNode *h=head;
        int i=0,a=0;
        while(h)
        {
            i++;
            h=h->next;
        }
        h=head;
        while(h)
        {
            i--;
            a+=(h->val?pow(2,i):0);
            h=h->next;
        }
        return a;
#endif
    }
};
```