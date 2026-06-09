思路比较简单，就是一次遍历整个链表，奇数的存一下，偶数的存一下。最后把奇数的末尾指向偶数的头即可。

```
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        //链表为空，直接返回空
        if (head == nullptr) {
            return nullptr;
        }
        //链表只有一个头结点，返回头结点即可。
        if (head->next == nullptr) {
            return head;
        }
        //申请一个奇数链表和一个偶数链表的哨兵结点
        ListNode * odd = new ListNode(-1);
        ListNode * even = new ListNode(-1);
        ListNode * temp = head;
        //记录一下哨兵结点
        ListNode * oddCopy = odd;
        ListNode * evenCopy = even;
        //索引从1开始
        int index = 1;
        while(temp) {
            if (index %2 != 0) { //索引为奇数，把它添加到奇数链表里
                odd->next = temp;
                odd = odd->next;
            } else {//索引为偶数，把它添加到偶数链表里
                even->next = temp;
                even = even->next;
            }
            index ++;
            temp = temp->next;
        }
        even->next = nullptr;//偶数链表因为在后面，所以最后一个结点的尾部要赋空
        odd->next = evenCopy->next;//将奇数链表的尾部指向偶数链表的头
        return oddCopy->next;//返回奇数链表头

    }
};
```
