### 解题思路
注意k>size 取模,链表为空或者k为零。
1，开始快慢指针都指向头节点
2，快指针先走k个，然后快慢指针一块走，直到快指针的下一个是空，我们要返回的节点就是慢指针的下一个fir->next;
3，开始交换，首先让快指针指向头节点，慢指针指向空
4，返回刚才保存的待返回节点

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||k==0) return head;
        ListNode* fir = head;
        ListNode* sec = head;
        ListNode* t = head;
        int n = 0;
        while(t)
        {
            n++;
            t = t->next;
        }
        k = k%n;
        while(sec&&k)
        {
            sec = sec->next;
            k--;
        }
        while(sec->next)
        {
            fir = fir->next;
            sec = sec->next;
        }
        
        sec->next = head;
        
        ListNode* ret = fir->next;
        
        fir->next = NULL;
        
        return ret;
    }
};
```