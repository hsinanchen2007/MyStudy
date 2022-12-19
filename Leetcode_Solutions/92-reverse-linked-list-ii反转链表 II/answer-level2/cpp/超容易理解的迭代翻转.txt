### 解题思路
特殊情况就不分析了，代码里有
一般情况时，考虑到当从第一节点就翻转的话，因此新增一个头结点。
设置一个before节点用于记录第m-1个节点的位置；一个遍历链表的节点curr；
一个start节点用于记录第m个节点。当curr遍历到第m+1...n个节点时，只需
将每个节点插入到before与start之间即可。而curr遍历到第n+1个节点时，将
curr与start相连即可。

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
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    { 

        //计算长度
        ListNode *temp = head;
        int len = 0;
        while(temp!=NULL)
        {
            len++;
            temp = temp->next; 
        }

        //特殊情况
        if(m>n || m<1 || n>len)
            exit(-1);
        if(head==NULL || len==1) //注意长度为一时
            return head;

        //考虑到如果m=1时即从头开始翻转的情况，因此要加个新的头结点
        ListNode *result = new ListNode(0);
        result->next = head; 
        ListNode *before = result; //用于保存第m-1个节点
        ListNode *curr = result->next; //用于遍历链表的,一直遍历到第m+1个节点
        ListNode *start; //用于保存第m个节点
        ListNode *temp1, *temp2; //每次在before与temp1之间插入temp2

        int path = 1; //curr目前到达第几个节点
        while(path <= n)
        {
            //未到达起始翻转位置时继续向下遍历
            if(path < m)
            {
                before = before->next; 
                curr = curr->next;
            }
            //到达m节点时记下起始翻转的节点位置
            if(path == m)
            {
                start = curr;
                temp1 = start;
                curr = curr->next;
            }
            //将第m+1到第n个节点每次赋给temp2, 再插入到before与temp1之间
            if(path > m && path <= n)
            {
                temp2 = curr;
                curr = curr->next;
                before->next = temp2;
                temp2->next = temp1;
                temp1 = temp2;
            }
            path++;
        }
        //第n+1个及之后的不用遍历了，直接连在第m个节点即start后面即可
        start->next = curr;
        return result->next;
    }
};
```