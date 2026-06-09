### 解题思路
思路在注释里写了

### 代码
![图片.png](https://pic.leetcode-cn.com/2385d2b0159a832664f3817e156806d93aba1c30a71ad7a7747ad9d410832c11-%E5%9B%BE%E7%89%87.png)

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
//通过快慢指针找到中间结点
//通过头插法将链表前半段反转
//最后比较
    bool isPalindrome(ListNode* head) {
        if(head == NULL)
            return true;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next){//快慢指针找中间结点
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* p = head;
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        while(p->next != slow && p->next != NULL){//头插法反转前半段
            ListNode* r = p->next;
            p->next = r->next;
            r->next = dummyHead->next;
            dummyHead->next = r;
        }
        p = dummyHead->next;
        if(fast)//如果慢指针指向正中间的结点
            slow = slow->next;
        while(slow){//比较是否为回文
            if(slow->val != p->val)
                return false;
            slow = slow->next;
            p = p->next;
        }
        return true;
    }
};
```