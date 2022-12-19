    我相信没做出来的同学，不是不会而是没有明白到底要去做什么
    按照题中的意思，参数node是要删除的结点
    你不需要遍历找到待删除结点
    只需要将待删除结点的下一结点值覆盖待删除结点的值，然后删除下一结点  //因为下一结点值已经被存储嘞
```
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;  //覆盖
        node->next=node->next->next;    //删除
    }
};
```
