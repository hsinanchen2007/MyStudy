## 反转一半链表----空间复杂度O(1)
**1. 利用快慢指针找到链表一半的位置
2. 反转前一半
3. 再进行对比**
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
        if(head==NULL || head->next==NULL) return true;
        ListNode *p = head, *fast = head, *r = head, *q = NULL;
        while(fast && fast->next){
            fast = fast->next->next;
            r = p;
            p = p->next;
            r->next = q;
            q = r;
        }
        if(fast){
            p = p->next;
        }
        while(p && q){
            if(p->val != q->val) return false;
            p = p->next;
            q = q->next;
        }
        return true;
    }
};
```
## 借助vector数组
**将链表的结点值全部读到数组中，再判断数组是否对称**
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
        vector <int> nums;
        while(head){
            nums.push_back(head->val);
            head=head->next;
        }
        for(int i=0, j=nums.size()-1; i<j; i++, j--){
            if(nums[i]!=nums[j]) return false;
        }
        return true;
    }
};
```