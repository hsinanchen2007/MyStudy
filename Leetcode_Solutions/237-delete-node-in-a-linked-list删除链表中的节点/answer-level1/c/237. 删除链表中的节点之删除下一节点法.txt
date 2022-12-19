### 解题思路
1、这是道沙雕题目，考阅读理解能力！！！题目其实可以简化为一句话：删除链表中给定值为x的节点
2、当下一节点存在时，先赋值，然后直接删除下一节点
3、当下一节点不存在时，直接删除当前节点

### 代码
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    if(node->next){
        node->val=node->next->val;
        node->next=node->next->next;
    }else if(!node->next){
        free(node);
    }
}
```