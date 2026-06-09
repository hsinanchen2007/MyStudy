思路：
我将此方法戏称为“换头术*”：记录原本头(节点)的位置`pos=head`，不停地将下面第一个备用的头`pos->next`作为新的头放到现有头节点`head`的上方(作为其前继)，直到无头可换`pos->next==NULL`，结束循环。
```
struct ListNode* reverseList(struct ListNode* head){
    if(head==NULL || head->next==NULL) return head;
    struct ListNode* cur, * pos=head;
    while(pos->next!=NULL){
        cur = pos->next;
        pos->next = cur->next;
        cur->next = head;
        head = cur;
    }
    return head;
}
```
![image.png](https://pic.leetcode-cn.com/4b56bf83b69302dc419d561e2218be68a9b82a545e79afd301b7da1290d6c22b-image.png)

