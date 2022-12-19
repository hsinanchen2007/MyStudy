### 解题思路
自底向上归并，从长度1到超过链表长度来设置归并段的长度，
![mmexport1578837551549.jpg](https://pic.leetcode-cn.com/2c3007792fbd492bfa92fad7f482b6e7eb9de91b6ad8ae9c541648b4d81a4169-mmexport1578837551549.jpg)



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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {//这代码直接复制21题合并两个有序链表
        if (l1 == NULL) {
            return l2;
        }
        else if (l2 == NULL) {
            return l1;
        }
        ListNode res(-1), *r;
        r = &res;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                r->next = l1;
                l1 = l1->next;
                r = r->next;
            }
            else
            {
                r->next = l2;
                l2 = l2->next;
                r = r->next;

            }
        }
        if (l1 != NULL)
        {
            r->next = l1;
        }
        if (l2 != NULL)
        {
            r->next = l2;
        }
        return res.next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL||head->next == NULL)
        {
            return head;
        }
        int listlen = 1;    //在后面计算整个链表长度
        ListNode *p = head; 
        ListNode *h1, *h2, *q, *r, *t, *h;
        //p,q主要用来指向要合并的2个链表，
        //h1指向要merge的链表的哨兵节点，h2指向要merge链表最后一个节点的下一个节点
        //h是整个链表的哨兵节点
        h = new ListNode(-1);   //给链表加个哨兵节点
        h->next = head;
        while (p->next != NULL) //计算链表长度
        {
            p = p->next;
            listlen++;
        }
        //sortsize是当前1个归并段的长度，每次乘2，即左移1；当sortsize大于整个链表长度就停止
        for (int sortsize = 1; sortsize < listlen; sortsize <<= 1)
        {
            //对整一个链表排序，每次对2个长度为sortsize的链表进行归并
            h1 = h;//上面有解释，归并结果的哨兵节点
            h2 = h;//这里为了满足下面一行的条件，随便给个不是NULL的
            while (h2 != NULL)
            {
                p = h1->next;//p是真正要归并的第一个链表的第一个节点
                t = p;
                int i = 0;
                while (i < sortsize && t->next != NULL)//找p链末尾
                {
                    i++;
                    r = t;  //r是记录t的上一个节点
                    t = t->next;
                }
                if (i == sortsize) //p的最后的下一个不是整个链表的末尾
                {
                    q = t;  //q是真正要归并的第二个链表的第一个节点
                    r->next = NULL; //第一个链表与第二个链表断开
                    h1->next = NULL;//第一个链表与他第一个节点的前一个节点断开，p链表独立
                }
                else                //不用归并，q为空
                {
                    break;
                }
                i = 0;
                //找q链表末尾并找到末尾的下一个节点赋给h2
                while (i < sortsize && t->next != NULL)
                {
                    i++;
                    r = t;
                    t = t->next;
                }
                if (i != sortsize)  //遍历到整个链表末尾，不用与后面断开
                {
                    h2 = t->next;   //应该是NULL了
                }
                else                //断开第二个链表的后面
                {
                    h2 = r->next;
                    r->next = NULL;
                }

                h1->next = mergeTwoLists(p, q);//归并pq链表，并接到哨兵节点后
                //把当前归并长度所剩下的链表接到归并结果后
                while (h1->next != NULL)    
                {
                    h1 = h1->next;
                }
                h1->next = h2;
            }
        }
        return h->next;
    }
};
```
