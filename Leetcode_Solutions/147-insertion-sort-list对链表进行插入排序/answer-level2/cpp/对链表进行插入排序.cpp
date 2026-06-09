### 解题思路

插入排序算法：
1. 插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
2. 每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
3. 重复直到所有输入数据插入完为止。


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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* p = head->next;   // p 指向每次迭代中一个待排序的元素，p 之前的链表是排好序的
        ListNode* pr = head;        // pr 指向 p 的前一个结点
        
        // 在原有链表的基础上进行排序
        while(p)
        {
            ListNode* q = head;     
            ListNode* qr = head;

            // 在头结点至 p 结点之间，搜索适当的位置 q，来插入 p
            while(q != p && p->val > q->val)
            {
                qr = q;    // qr 指向 q 的前一个结点
                q = q->next;
            }

            // 当 q 和 p 指向同一个结点时，表示 p 结点的元素比 p 结点前面所有的元素都要大；
            // 此时，链表不作变动，p 指向下一个结点。
            if(q == p)      
            {
                pr = p;
                p = p->next;
            }
            else
            {
                pr->next = p->next; // 将 p 结点从原来的位置移除
                p->next = q;        // 将 p 插入 q 结点的前面

                if(q == head)   // 此时，p 的元素值小于等于头结点的值，将 p 作为头结点
                {
                    head = p;
                }
                else
                {
                    qr->next = p;   // 将 p 插入 qr 与 q 之间
                }

                p = pr->next;   // p 指向下次迭代中一个待排序的元素
            }
        }

        return head;
    }
};
```

### 复杂度分析
时间复杂度：插入排序的时间复杂度为 $O(n^2)$，其中 $n$ 表示链表的结点数。
空间复杂度：$O(1)$。
