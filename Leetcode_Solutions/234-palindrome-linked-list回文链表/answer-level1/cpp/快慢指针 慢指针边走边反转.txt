快慢指针 慢指针边走边反转。走到中点后慢指针继续往前，pre也超着next的方向往后，逐个对比val是否相等

```
class Solution {
public:
    bool isPalindrome(ListNode* head) {
      if(head == NULL || head->next == NULL) return true;
      ListNode *fast(head), *slow(head), *pre(0), *temp;
      while(fast != NULL && fast->next != NULL)
      {
        fast = fast->next->next;
        //reverse慢指针
        temp = slow->next;
        slow->next = pre;
        pre = slow;
        slow = temp;
        if(fast != NULL && fast->next == NULL)//更新后链表为奇
        {
          slow = slow->next;
        }
      }
      while(pre != NULL && slow != NULL)
      {
        if(pre->val != slow->val) return false;
        pre = pre->next;
        slow = slow->next;
      }
      return true;
    }
};
```
![image.png](https://pic.leetcode-cn.com/4099394b8b6299686d0b3afb1506107e89321ef0ce16e143850979d2d53eb818-image.png)

