![image.png](https://pic.leetcode-cn.com/33b6d0864c22e6dc5b28b94b44c6cbcbd100078ebd6e8903fb3830c082d8db57-image.png)

### 解题思路
读一下我的图，球球你了。
![image.png](https://pic.leetcode-cn.com/845ef9a0d08a93a0260f3f82370c2990772eac12d0dd52dc6ceab141857c8367-image.png)

<br>
- 看懂上图后，我们就知道为什么在相遇后我们让其中一个指针指向链表开头，然后同步移动，直至再次相遇，相遇点就一定是入口点了。

- 显然本题关键在于图中的等式，而这个等式用到的速度概念就是小学初中的。
- ~~代码注释详细。~~ 不需要注释了吧。
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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;
        ListNode* slow = head, *fast = head;
        while(fast){
            if(!fast->next) return nullptr;
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) break;  
        }
        if(!fast) return nullptr; // 如果是找到空指针而退出的while，说明没环
        slow = head;
        while(slow!=fast){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
```
- 有收获的话求赞