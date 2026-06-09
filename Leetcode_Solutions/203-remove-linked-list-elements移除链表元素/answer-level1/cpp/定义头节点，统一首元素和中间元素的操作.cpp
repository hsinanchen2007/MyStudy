```
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode headNode(0);  //定义头节点
        headNode.next =head;   //头节点的next指向head
        ListNode* pre=&headNode;  //前继指针指向头节点
        ListNode* it = head;     //迭代指针指向head
        while(it!=nullptr){
            //这样一来，首元素与中间元素都可用下面的算法去迭代
            if(it->val==val){
                pre->next = it->next;
                it->next = nullptr;
                it=pre->next;
            }
            else{
                pre= it;
                it= it->next;
            }
        }
        //记得返回的是headNode.next，因为head在迭代的过程中可能被改变了
        return headNode.next; 
    }
};
```
