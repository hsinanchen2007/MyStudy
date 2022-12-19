*执行用时 :8 ms, 在所有 C++ 提交中击败了97.90%的用户
内存消耗 :8.9 MB, 在所有 C++ 提交中击败了86.87%的用户*

其实快的地方就在于双指针这个点
具体可以参考19题：**19.删除链表的倒数第N个节点**
1. 然后得出两个指针slow指向链表中间，fast指向链表结尾，和一个节点个数listnode_size
2. 然后要让链表变环，用fast->next=head;就可以
3. 然后再化简下旋转次数k，比如说节点只有3个，那k=4，旋转了3次就和原来一样了，所以只用旋转1次就好
4. 接下来就是要找倒数第k+1个节点就好了(这里的k已经经过第二步化简过了)
比如说1->2->3->4，k=1，那你需要找到倒数第2个节点即为3，令指针p指向3这个节点
那么head=p->next;p->next=NULL即可

```
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL)
            return head;
        int listnode_size=1;
        ListNode* pointer_fast=head,*pointer_slow=head;
        //因为有报错原因所以写法有点别扭
        //直接看成while(pointer_fast->next->next!=NULL)，且里面没有if那一行即可
        while (pointer_fast->next!=NULL)
        {
            if (pointer_fast->next->next!=NULL)
            {
                pointer_fast=pointer_fast->next->next;
                pointer_slow=pointer_slow->next;
                listnode_size=listnode_size+2;
            }
            else
                break;  
        }
        if (pointer_fast->next!=NULL)
        {
            pointer_fast=pointer_fast->next;
            ++listnode_size;
        }
        //实际移动次数，但要找的是倒数第k+1个节点
        k=k-k/listnode_size*listnode_size;
        if (k==0 || listnode_size==1)
            return head;
        pointer_fast->next=head;
        if (k>listnode_size/2)//前半段
        {
            //pointer_fast作为一个工具指针，不再指向最后一个节点
            pointer_fast=head;
            for (int i=listnode_size-k-1;i>0;--i)
                pointer_fast=pointer_fast->next;
            head=pointer_fast->next;
            pointer_fast->next=NULL;
        }
        else//后半段
        {
            for (int i=listnode_size/2-k;i>0;--i)
                pointer_slow=pointer_slow->next;
            head=pointer_slow->next;
            pointer_slow->next=NULL;
        }
        return head;
    }
};
```

