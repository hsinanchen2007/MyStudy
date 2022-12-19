仔细读题目，你会发现和快排的分区操作很像，只是这里变成了链表形式。在分区进行交换时，可以交换节点，也可以交换节点中的值

#### 交换节点值
```c++
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *p1 = head, *p2 = head;
        while(p2)
        {
            if(p2->val < x)
            {
                int tmp = p2->val;
                p2->val = p1->val;
                p1->val = tmp;
                p1 = p1->next;
            }
            p2 = p2->next;
        }
        return head;
    }
};
```

#### 交换结点
链表相比数组优势在于插入和删除时间复杂度都为O(1)。为此可以遍历链表，遇到小于x的节点，就将该结点放到链表的最前面，即可完成分区操作。
```c++
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode  *p = head, *pp = head,*hd = head;
        while(p)
        {
            // 添加p != hd，防止头结点成环
            if(p->val < x && p != hd)
            {
                // 下三行表示将该结点从链表中删除，并更新p和pp
                ListNode *tmp = p;
                p = p->next;
                pp->next = p;
                // 将结点插入到头部
                tmp->next = hd;
                hd = tmp;
            }
            else
            {
                pp = p;
                p = p->next;
            }
        }
        return hd;
    }
};
```