### 解题思路
这道题和一道大于小于x的元素重新排列链表的题目思路相同，题号忘了。重要的是掌握这个方法。

### 代码

```cpp
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(0);
        ListNode* even = new ListNode(0);
        ListNode* re = odd;
        ListNode* evenstart = even;
        bool isodd = true;
        while (head != NULL) {
            if (isodd) {
                odd->next = head;
                odd = odd->next;
            }
            else {
                even->next = head;
                even = even->next;                
            }
            isodd = !isodd;
            head = head->next;
        }
        odd->next = evenstart->next;
        even->next = NULL;
        return re->next;
    }
};
```