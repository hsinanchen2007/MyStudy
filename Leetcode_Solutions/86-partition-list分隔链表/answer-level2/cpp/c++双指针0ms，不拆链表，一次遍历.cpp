### 解题思路
使用哑结点，两个指针flag和p分别指向分界点元素和当前元素，让p遍历整个链表，如果遇到比x小的结点就挪到flag后，然后更新flag。对于比x大的结点直接跳过，因此不会改变结点的初始相对位置。最后返回哑结点的下一个结点即可。具体看代码实现
时间复杂度：O（N），我们遍历了整个链表一次
空间复杂度：O（1）， 我们只有一个哑结点占用了额外空间。

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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        ListNode *pre = new ListNode(0);//哑结点
        pre->next = head;

        ListNode *flag = pre;
        //flag指向第一个比目标值大的结点的前一个
        while(flag->next && flag->next->val < x) flag = flag->next;

        ListNode *p = flag->next, *q;
        while(p){
            if(p->next && p->next->val < x){
                q = p->next;
                p->next = q->next;
                q->next = flag->next;
                flag->next = q;
                flag = flag->next;
            }
            else p = p->next;
        }
        return pre->next;
    }
};
```
![Snipaste_2020-01-31_12-05-02.png](https://pic.leetcode-cn.com/62839dbd84ba4b98450a9eb7cb5a2578dbcbd967eeb76a84488789647722cd55-Snipaste_2020-01-31_12-05-02.png)
