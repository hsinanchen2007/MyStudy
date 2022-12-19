### 解题思路
这道题的最重要的一个思路是找最后一个节点的前第k个节点！
那么我们要判断链表长度len和k的关系：
① k%len==0
这种情况直接返回head就好，因为旋转后是一样的。
② k>len
这样就要取新的k=k%len
③ k<len

以上三种情况都是为了k要小于len
然后我们找最后一个节点的前第k个节点
定义一个start节点，start->next=head.实际上这个start是为了方便操作而创建，这个用处很多，感兴趣的读者自己查阅一下资料，叫额外的头节点。
定义一个tmpHead和tmpRear，tmpHead是较前的一个节点，tmpRear是较后的节点
tmpHead先往前走k次，然后tmpHead和tmpRear一起走，直到tmpHead是最后一个节点（tmpHead->next==NULL)

后面就简单了，就是指来指去的问题了
首先，tmpHead->next=head;
然后，start->next=tmpRear->next;
最后，tmpRear->next=NULL;
![image.png](https://pic.leetcode-cn.com/61d483545f268a38b33f673cf630106d16271cbd02df01dcb624c243d86c19b1-image.png)

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        if(k==0) return head;
        ListNode * start=new ListNode(0);
        start->next=head;
        ListNode* tmpHead=start;
        ListNode* tmpRear=head;
        int len=0,tmpk=k;
        while(tmpHead->next!=NULL &&tmpk>0)//这一步是为了判断len和k的关系
        {
            tmpk--;
            len++;
            tmpHead=tmpHead->next;
        }
        if(k%len==0 && tmpHead->next==NULL ) return head;//①
        if(tmpk==0)//③
        {
            tmpHead=tmpHead->next;
            while(tmpHead->next!=NULL)
            {
                tmpHead=tmpHead->next;
                tmpRear=tmpRear->next;
            }
        }
        else if(len<k)//②
        {
            tmpk=k%len;
            tmpHead=head;
            while(tmpk-->0)
            {
                tmpHead=tmpHead->next;
            }
            while(tmpHead->next!=NULL)
            {
                tmpHead=tmpHead->next;
                tmpRear=tmpRear->next;
            }
        }
        tmpHead->next=start->next;
        start->next=tmpRear->next;
        tmpRear->next=NULL;
        return start->next;
    }
};
```