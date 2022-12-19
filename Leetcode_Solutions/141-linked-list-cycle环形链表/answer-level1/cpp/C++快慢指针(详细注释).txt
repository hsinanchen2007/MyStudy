![图片.png](https://pic.leetcode-cn.com/ec341ab6f13be23e031e0f20abf2cac3aee3b2e8b210fe1d5f5c85cd23a72aeb-%E5%9B%BE%E7%89%87.png)
```
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
    bool hasCycle(ListNode *head) {
        ListNode* slow,*fast;
        fast = slow = head;
        //如果链表中为空或者只有一个结点,那么肯定不存在环
        if(head==NULL||head->next==NULL)
            return false;
        //因为快指针走得快,所以只用根据快指针判断即可
        while(fast!=NULL&&fast->next!=NULL&&fast->next->next!=NULL){
            fast = fast->next->next;//快指针走两步
            slow = slow->next;//慢指针走一步
            if(slow==fast)//如果快慢指针相遇则肯定有环
                return true;
        }
        return false;
    }
};
```
