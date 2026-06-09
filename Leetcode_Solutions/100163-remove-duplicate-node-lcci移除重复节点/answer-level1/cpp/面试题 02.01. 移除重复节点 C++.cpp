### 解题思路
1、使用hashset保存首次出现的值   时间复杂度O(N)、空间复杂度O(N)

2、删除当前节点后面的值等于它的所有节点   时间复杂度O(N^2)、空间复杂度O(1)
### 代码

```cpp

class Solution {
public:
    //方法1:
    ListNode* removeDuplicateNodes(ListNode* head) {

        if (head == nullptr)
            return head;

        //第一个节点不会删除
        unordered_set<int> set;
        set.insert(head->val);

        //从第二个节点开始删除
        ListNode* prev = head;
        while (prev->next)
        {
            if (set.find(prev->next->val) != set.end()) //值重复
            {
                prev->next = prev->next->next;
            }
            else //值首次出现
            {
                set.insert(prev->next->val);
                prev = prev->next;
            }
        }
        return head;
    }


    //方法2:
    ListNode* removeDuplicateNodes(ListNode* head) {

        if (head == nullptr)
            return head;

        ListNode* cur = head;

        while (cur)
        {
            ListNode* prev = cur;
            while (prev->next) //遍历到链表尾，删除值等于cur->val的所有节点
            {
                if (prev->next->val == cur->val)
                {
                    prev->next = prev->next->next;
                }
                else
                {
                    prev = prev->next;
                }
            }
            
            cur = cur->next;
        }

        return head;
    }
};
```