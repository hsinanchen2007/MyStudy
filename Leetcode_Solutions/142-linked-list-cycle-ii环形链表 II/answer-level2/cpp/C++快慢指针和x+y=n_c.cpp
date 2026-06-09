### 解题思路
1、先判断有没有环；如果没有环，输出nullptr；有环，进入2；
2、相遇点slow在环里。x+y=n*c
设立一个a指向head，a走x步到达环起点，slow走x步也到环起点。
判断条件(a==head)。

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
//先找有没有环，再找入环的第一个节点
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr||head->next==nullptr) return nullptr;
        ListNode* quick=head;
        ListNode* slow=head;
        bool meet=false;
        while(slow!=nullptr&& slow->next!=nullptr&&quick!=nullptr&&
        quick->next!=nullptr&&quick->next->next!=nullptr)//
        {
            slow=slow->next;
            quick=quick->next->next;
            if(slow==quick)//有环,true,跳出循环；如果没有meet=false;
            {meet=true;break;}
        }
        if(meet==true)//有环
        {
            //调用函数 return entry(slow,head);
            ListNode* a=head;
            while(a!=slow)
            {
                a=a->next;
                slow=slow->next;
            }
            return a;
        }
        else//meet==false,没有环
        return nullptr;
    }

    /*ListNode* entry(ListNode* slow,ListNode* head)//有环，先找到环里有几个点，再用快慢指针法
    {//slow是环里的任意一点
        ListNode* node=slow;
        int num=1;//记录环里有多少个点
        while(node->next!=slow)
        {
            num++;
        }
        ListNode* s=head;
        ListNode* q=head;
        for(int i=0;i<num;i++)
        {
            q=q->next;
        }
        while(s!=q)
        {
            s=s->next;
            q=q->next;
        }
        return s;
    }*/
};
```