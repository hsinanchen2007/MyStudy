# **1.分治法**

实现方法其实和普通的归并排序差不多，最大的区别是这里我们每一次合并只需要处理两个链表就行了

```
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return 0;
        mergelist(lists,0,lists.size());  
        return lists[0];
    }
    
    void mergelist(vector<ListNode*>& lists,int l,int r)
    {
        if(r-l<2)return;
        auto mid=l+(r-l)/2;
        mergelist(lists,l,mid);
        mergelist(lists,mid,r);
        lists[l]=mergeTwoLists(lists[l],lists[mid]);
        
    }
    
   ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
     if(l1==0)return l2;
     if(l2==0)return l1;
     auto res=l1;
     ListNode* pre=0;
        while(l1&&l2)
        {
            if(l1->val>=l2->val)
            {
                if(pre)
                {  
                    auto temp=l2->next;
                    pre->next=l2;
                    l2->next=l1;
                    pre=l2;
                    l2=temp;
                }
                else 
                {
                    auto temp=l2->next;
                    l2->next=l1;
                    pre=l2;
                    res=l2;
                    l2=temp;
                }
            }
            else
            {
                 pre=l1;
                l1=l1->next;   
            }
            
        }
      if(l2) pre->next=l2;
      return res;    
    }
    
};

```
# **优先级队列**

这里我们直接将每一个链表的首**节点**加入优先级队列中，因此需要定义一个比较函数对象cmp;
然后进入循环每次取出堆顶元素（链表的某个节点），如果该节点存在下一个节点那么将其加入堆。

```
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return 0;
        auto cmp=[](ListNode*p1,ListNode*p2){return p1->val>p2->val;};
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)>heap(cmp);
         ListNode* head=0;
         auto pre=head;
        for(auto c:lists)
        {   
            if(c)
            heap.push(c);   
        }
        
        while(!heap.empty())
        {
            auto x=heap.top();
            heap.pop();
            if(head==0)
            {
                head=x;
                pre=x;
            }
             else 
             { 
              pre->next=x;
              pre=x;
             }           
          if(x&&x->next) heap.push(x->next);  
        }
        return head;
    }
};
```
