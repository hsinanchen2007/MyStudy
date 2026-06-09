### 解题思路
![image.png](https://pic.leetcode-cn.com/dfd71a17ef156425db089527cd1024d0ddc8c60f4f188eeadedc63f2b204c321-image.png)

此处撰写解题思路
先用双指针找到中间点，处于练习目的，反转前半链表，而后遍历是否有差。
### 代码

```cpp

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next){
            return true;
        }
        if(!head->next->next){
            return head->val == head->next->val? true:false;
        }
        //two ptrs find the mid point
        ListNode* pseudoHead = new ListNode(0);
        pseudoHead->next = head;
        ListNode* fast = head;
        ListNode* slow = pseudoHead;
        int count = 0;
        while(fast){
            fast = fast->next;
            count++;
            slow = slow->next;
            if(fast){
                fast = fast ->next;
                count++;
            }
        }
        //fast ptr points to the second half of the list;
        fast = slow->next;
        bool isEven = count%2==0? true:false;
        //revert first half of the list;
        ListNode* ptr1 = head;
        ListNode* ptr2 = ptr1->next;
        ListNode* ptr3 = ptr2->next;
        while(ptr2!=fast){
            pseudoHead->next = ptr2;
            ptr2->next = ptr1;
            head->next = ptr3;

            ptr1 = ptr2;
            ptr2 = ptr3;
            ptr3 = ptr2->next;
        }
        
        head = pseudoHead->next;
        ptr1 = isEven? head:head->next;
        
        while(fast){
            if(ptr1->val != fast->val){
                return false;
            }
            fast = fast->next;
            ptr1 = ptr1->next;
        }
        return true;
    }
};

```