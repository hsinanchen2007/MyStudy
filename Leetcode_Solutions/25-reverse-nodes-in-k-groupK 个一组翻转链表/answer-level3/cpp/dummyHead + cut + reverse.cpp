### 解题思路
这道题要求了常数级的空间复杂度，也就是说明翻转时不能借助辅助数据结构，所以reverse部分使用迭代法加双指针
dunnyHead的作用就是将切断后并且翻转完成的链挂在dummyhead上
cut函数相比以往的cut函数有所不同，他多了一个引用型入参，当成传出参数使用，使cut返回余下链表的首部,同时返回是否正好切K个
总流程：设置头结点->切K个节点下来->判断是否正好切了K个->如果是的话，将切下来的翻转，并挂在头上，并继续往下切。不是的话直接挂在头上，结束程序。

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        bool flag = true;
        ListNode dummyNode(0);
        dummyNode.next = head;
        ListNode *p = &dummyNode,*s = head;
        while(s!=NULL)
        {
            ListNode *left = cut(s,k,flag);
            if(flag)
            {
                p->next = reverse(s);
                
            }
            else
            {
                p->next = s;
            }
            while(p->next!=NULL) p = p->next;
            s = left;
        }

        return dummyNode.next;

    }



    ListNode* reverse(ListNode* l)
    {
        if(l == NULL)
            return NULL;
        ListNode *pp=NULL,*cur=l,*pn=l->next;
        while(pn!=NULL)
        {
            cur->next = pp;
            pp = cur;
            cur = pn;
            pn = pn->next;
        }
        cur->next = pp;
        return cur;
    }





    ListNode* cut(ListNode* l , int step , bool& flag)
    {
        if(l == NULL)
        {
            flag = false;
            return NULL;
        }
        for(int i=0;i<step-1;++i)
        {
            if(l->next ==NULL)
            {
                flag = false;
                return NULL;
            }
            l = l->next;
        }
        ListNode* temp = l->next;
        l->next = NULL;
        flag = true;
        return temp;
    }
};
```