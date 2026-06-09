### 思路
1. 使用快指针找到第一个大于等于 x 的节点，将插入节点 `ins` 停留在这个节点前面
2. 使用快指针找到后续小于 x 的节点，将删除节点 `rem` 停留在这个节点前面
3. 将 `rem->next` 转移到 `ins->next`
4. 为了保持顺序，将 `ins = ins->next`

### 答题
```C++ []
ListNode* partition(ListNode* head, int x) 
{
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* fast = head;
    ListNode* ins = dummy;
    ListNode* rem = dummy;
    while (fast != nullptr && fast->val < x)
    {
        fast = fast->next;
    }
    while (ins != nullptr && ins->next != fast)
    {
        ins = ins->next;
    }
    while (fast != nullptr)
    {
        if (fast->val < x)
        {
            while (rem != nullptr && rem->next != fast)
            {
                rem = rem->next;
            }
            if (rem == nullptr) break;
            ListNode* temp = ins->next;
            ins->next = rem->next;
            rem->next = rem->next->next;
            ins->next->next = temp;
            ins = ins->next;
        }
        fast = fast->next;
    }
    return dummy->next;
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

