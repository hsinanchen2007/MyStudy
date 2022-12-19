

![1.png](https://pic.leetcode-cn.com/2a6450e588dee701afc442dc347723b7a6bf34aee4fcbe65bc3bf5d51ec976e3-1.png)

```C++
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *temp = new ListNode(0);//设置头节点统一操作
        ListNode *pre,*curr;//前置节点和现结点
        temp->next=head;//连通头节点和给定链表
        pre=temp;//指向头节点
        curr=temp->next;//指向第一个节点
        while(curr!=NULL){
            while(curr->next!=NULL && (curr->val==curr->next->val)){
                curr=curr->next;//如果下一个节点仍然和这个节点相等，则继续向后移动直至curr指向重复的最后一个节点
            }
            if(pre->next != curr){//即存在重复节点
                pre->next=curr->next;//直接指向重复的最后一个结点的下一个节点。 #此处也可以添加一行代码delete掉那些重复节点的空间
                curr=curr->next;//指针后移
            }
            else{
                curr=curr->next;
                pre=pre->next;
            }
        }

        return temp->next;


    }
};
```

