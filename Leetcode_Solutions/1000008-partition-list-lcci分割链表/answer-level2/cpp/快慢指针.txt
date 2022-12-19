




![image.png](https://pic.leetcode-cn.com/abfcb7e9e85c8fa8beb3f6ebdc55c559b2acbae99057a407015e1c1853980d34-image.png)

second一直指向第一个大于等于x的结点，first从second的位置开始向前探索，直到找到小于x的结点，然后与second交换，second向前移动。
```
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* first = head;
        while (first != nullptr && first->val < x) first = first->next;
        ListNode* second = first;
        while (true) {
            while (first != nullptr && first->val >= x) first = first->next;
            if (first == nullptr) break;
            swap(first->val, second->val);
            second = second->next;
        }
        return head;
    }
};
```
