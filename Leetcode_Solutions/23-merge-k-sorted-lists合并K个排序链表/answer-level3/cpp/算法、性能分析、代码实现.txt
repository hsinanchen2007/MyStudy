方法一：1）将k个链表的节点地址放入vector数组中；2）调用库函数sort（）依据节点的值从小到大排序（这里需要重写cmp函数，以依据节点的数据域的值的大小排序）；3）修改next指针域，将排序后的vector中的节点重新连接成新链表；4）返回新链表头指针vector[0]。这个算法，思路清晰，代码简单。

性能分析：因为采用STL中的排序算法，时间复杂度为O（kn*logkn）,空间复杂度为O（kn）,其中k为输入的链表个数，n为链表平均长度；
运行结果：通过，64ms(48.46%),11.3MB(79.34%)
```
bool cmp (const ListNode* a,const ListNode* b){
    return a->val<b->val;
}

class Solution {
public:  
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode *>node_ptr_vec;
        ListNode *head;
        for(int i=0;i<lists.size();i++){
            head=lists[i];
            while( head){
                node_ptr_vec.push_back( head );
                head=head->next;
            }
        }
        if(node_ptr_vec.size()==0)
            return NULL;
        sort(node_ptr_vec.begin(),node_ptr_vec.end(),cmp);
        for(int i=0;i<node_ptr_vec.size()-1;i++)
            node_ptr_vec[i]->next=node_ptr_vec[i+1];
        node_ptr_vec[node_ptr_vec.size()-1]->next=NULL;
        return node_ptr_vec[0];
    }
};
```
方法二：分治策略的典型适用情况，分治的实现可以采用递归、迭代循环等方法。我这里借助双端队列deque（利用其头尾删除添加快捷的性质）采用循环迭代实现。1）首先遍历lists数组，将非空的list push进deque中。2）如果deque为空，则可返回NULL并退出，如果非空，则deque的长度必然大于等于1。3）用while循环deque，在循环中，将deque的后两个进行合并操作（这一步可以专门编写一个函数，实际上可以拿21题两个链表的代码直接用），同时将这两个pop_back出去，将合并后新头指针push_front进deque的头部；直到deque的长度为一，退出循环。4）返回deque中仅有的一个元素即可。

性能分析：采用分治归并，时间复杂度为O(kn*logk);空间复杂度O(k).
运行结果：131/131 通过 36ms(89.68%),11.7MB(75.31%).

```
//合并两个链表的函数
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *p2=l1;
    l1=new ListNode(-9999999999999);//临时节点
    l1->next=p2;
    ListNode *p1=l1;
    while(l2&&p2){
        if(p1->val<=l2->val&&l2->val<=p2->val){
            p1->next=l2;
            p1=l2;
            l2=l2->next;
            p1->next=p2;      
        }
        else{
            p1=p2;
            p2=p2->next;
        }
    }
    if(!p2)
        p1->next=l2;
    return l1->next;  
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        deque< ListNode*>head_ptr_deque;
        for(int i=0;i<lists.size();i++){
            if(lists[i]){
                head_ptr_deque.push_back(lists[i]);
            }
        }
        if(!head_ptr_deque.size())
            return NULL;
        ListNode *p1;
        ListNode *p2;       
        while(head_ptr_deque.size()!=1){
            p1=head_ptr_deque.back();
            head_ptr_deque.pop_back();
            p2=head_ptr_deque.back();
            head_ptr_deque.pop_back();
            //调用上面合并两个链表的函数
            head_ptr_deque.push_front(mergeTwoLists(p1, p2));
        }
        return head_ptr_deque.back();
    }
};
```

欢迎指正交流，拒绝撕逼，谢谢



    
