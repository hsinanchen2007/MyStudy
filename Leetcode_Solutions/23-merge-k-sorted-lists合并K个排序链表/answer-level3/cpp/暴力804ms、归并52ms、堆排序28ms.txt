**1.暴力解决**
遍历k个排序链表，每次找其中的最小值，加入结果链表中，并将最小值所在的链表指针向后移动一位，直到所有链表全部遍历完成
时间复杂度：O(k*n)

```cpp
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head=NULL,*q=NULL;
        int min=99999,temp=-1;
        int flag=0;
        while(1)
        {
            flag=0;         //flag==0 全为空链表
            for(int i=0;i<lists.size();i++)
                if(lists[i])
                   flag=1;
            if(flag==0)
               break;
            min=99999,temp=-1;
            for(int i=0;i<lists.size();i++)    //每次找当前链表中最小值
                if(lists[i]&&lists[i]->val<min)
                {
                   min=lists[i]->val;
                   temp=i;
                }
            ListNode *p=new ListNode(lists[temp]->val);
            if(head==NULL)   //对结果链表的头结点分情况讨论，也可以设置虚拟的头结点
               head=q=p;
            else
            {
                q->next=p;
                q=p;
            }
            lists[temp]=lists[temp]->next;  //向后挪一位
        }
        return head;
    }
};
```
**2.归并排序**
多路归并，用二分的形式进行划分，每次对其中的两个链表进行排序
一共[log2(n-1)+1]次归并，每次参与的结点不多于n
时间复杂度: O(nlogn)

```cpp
class Solution {
public:
    ListNode* merge(ListNode *p,ListNode *q)   //对头结点指针为p,q的两个链表进行排序
    {
        ListNode *head=NULL,*s=NULL,*t=NULL;
        while(p&&q)
        {
            if(p->val<=q->val)
            {
               t=new ListNode(p->val);
               p=p->next;
            }
            else
            {
                t=new ListNode(q->val);   
                q=q->next;
            }
            if(head==NULL)
                head=s=t;
            else
            {
                s->next=t;
                s=t;
            }    
        }
        if(p==NULL&&q!=NULL)   //链上剩余部分
        {
            if(head==NULL)
               head=q;
            else
               s->next=q;
        }
        else if(q==NULL&&p!=NULL)  //链上剩余部分
        {
            if(head==NULL)
               head=p;
            else
               s->next=p;
        }
        return head;
    }
    
    //归并排序
    ListNode* mergesort(vector<ListNode*>& lists,int left,int right) {
        int m=0;
        if(right<left)
           return NULL;
        else if(right==left)  //只有一个链表，无需排序
                return lists[right];
        if(left+1==right)     //只有两个链表需要排序，无需再拆分
        {
             ListNode* head=merge(lists[left],lists[right]);
             return head;
        }
        else
            m=(right+left)/2;
        ListNode* p=mergesort(lists,left,m);
        ListNode* q=mergesort(lists,m+1,right);
        ListNode* h=merge(p,q);
        return h;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* h=mergesort(lists,0,lists.size()-1);
        return h;
    }
};
```

**3.堆排序**
使用最小堆排序
先将所有链表的头结点插入堆，每次弹出堆顶元素，并插入堆顶元素在其链表中的后一个元素，直到堆为空
堆内元素为 pair<int,ListNode*> 将pair.first设为负数可实现最小堆
时间复杂度：O(n*logn)

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>> heap;
        for(auto list:lists){
            if(list)
               heap.push({-list->val,list});
        }
        ListNode* first=new ListNode(-1);
        ListNode* cur=first;
        while(heap.size()){
            auto t=heap.top();
            heap.pop();
            if(t.second->next)
               heap.push({-t.second->next->val,t.second->next});
            cur->next=t.second;
            cur=cur->next;
        }
        cur->next=NULL;
        return first->next;
    }
};
```