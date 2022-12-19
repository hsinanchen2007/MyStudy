### 解题思路
首先来看使用快慢指针可以将时间复杂度降为O(N)
这道题难的地方在如何处理要删除的节点是头节点的情况 这里采用添加一个头节点的方法解决这个问题

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
 /*
 三种情况第一种是删除的元素是头节点 第二种是删除元素是中间节点 第三是删除元素为尾节点
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //添加一个头结点 避免头节点没办法删除
        ListNode* NewHead = new ListNode(0);
        NewHead->next = head;

        //ptr qtr为先走的指针
        //注意因为新建的头节点 他们必须初始化为head
        ListNode* ptr = NewHead;
        for(auto i = 0; i < n+1; i++)
            ptr = ptr->next;
        ListNode* qtr = NewHead;

        //然后一起走 当ptr->next ==nullptr qtr->next为目标
        while(ptr != nullptr)
        {
            ptr=ptr->next;
            qtr = qtr->next;
        }

        //改变数组
        qtr->next = qtr->next->next;

        //返回头节点
        return NewHead->next;
    }
};
```