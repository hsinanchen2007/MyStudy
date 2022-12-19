### 解题思路
遇到的坑：
1. 表头虚节点，两个指针，一个用于更新，一个用于遍历；额外创建一个指针用于标明表头。
2. 重点在于，遍历的指针（ptr）每次大循环都指在重复后的第一个元素上。而更新的指针在每次小循环遍历完毕之后，只更新next，不更新自身（避免了无法识别类似2,2,3,3这样连续的组合），在判断至少有两个不相等的数之后，才安全地更新自己。

### 代码

```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (NULL == head || NULL == head->next)
            return head;
        ListNode* dum = new ListNode(0);
        dum->next = head;
        //记录一下表头
        ListNode* mark_begin = dum;
        ListNode* ptr = head;
        while (NULL != ptr) {
            int a = 0;
            //跑到连续重复元素的末尾
            while (ptr->next && ptr->val == ptr->next->val) {
                ptr = ptr->next;
                a++;
            }
            //跑到重复元素后的第一个元素。我觉得这一步很重要！
            ptr = ptr->next;
            //a=0证明上边的小循环压根没跑过，那么ptr和ptr->next肯定是不等的，结合上一行，ptr跑到了重复元素后的第一个元素，
            //证明ptr和前后都不等，那么作为指针位置是安全的。
            if (a == 0)
                dum = dum->next;
            //只更新next，指针本身不动！
            else
                dum->next = ptr;
        }
        return mark_begin->next;
    }
};
```