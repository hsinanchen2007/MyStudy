![image.png](https://pic.leetcode-cn.com/74d0f7287c395cd4ecaa7b785ca64d95de8325aedbbfe8d0a15556e236ea7b5e-image.png)
```
利用两个指针，a是进行比较的结点，b是比较前的结点。
当啊结点的值是需要移除的值的时候，直接a=a->next;b->next=a;
这样就移除了值等于val的结点
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy=new ListNode(-1);//首节点可能会被删除
        dummy->next=head;
        ListNode* pre=dummy;
        while(head!=NULL){
            if(head->val==val){
                head=head->next;
                pre->next=head;
            }
            else{
                head=head->next;
                pre=pre->next;
            }
        }
        return dummy->next;
    }
};
```
