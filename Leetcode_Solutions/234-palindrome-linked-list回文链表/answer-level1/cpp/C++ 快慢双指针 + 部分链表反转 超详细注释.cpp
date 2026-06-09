### 解题思路
使用快慢指针找到中间点，反转前半部分链表，比较前后两部分链表是否一致

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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre = nullptr;
        ListNode* prepre = nullptr;
        while(fast != nullptr && fast->next != nullptr) {
            //边走边反转前半链表
            pre = slow;//先记录下pre，不然slow就指向下一个了

            //正常快慢指针走起，走完slow在链表长度是奇数的时候在中间位置， 偶数在中间两个元素的右边那个
            fast = fast->next->next;
            slow = slow->next;

            //这里实现链表反转
            pre->next = prepre;
            prepre = pre;//更新prepre
        }

        //链表长度为奇数，fast最终指向最后一个元素，slow指向中间的元素，这个元素不用比，直接比较前半部分和后半部分；
        //偶数时fast指向最后的nullptr, slow指向中间两元素的后一个，前后两部分刚好对称，自己画个图就明白了
        ListNode* p2 = fast==nullptr ? slow : slow->next;//后半部分链表

        ListNode* p1 = pre;//前半部分链表
        while(p1 != nullptr && p2 != nullptr) {
            if(p1->val != p2->val)
                return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return true;
    }
};
```