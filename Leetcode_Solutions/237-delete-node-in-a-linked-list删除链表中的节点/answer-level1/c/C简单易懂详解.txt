思路分析：
题目给出单链表，以及其中任意一个非末尾节点，还指出链表中所有节点的值都是唯一的。
知晓单链表中一节点等于可以知晓该节点其后所有节点而之前的节点地址是未知的，
依据单链表的这个特点我们只能从该节点后面想办法。要注意的是，节点在内存中什么位置我们通常不会关心，我们关心的是每个节点的数据域，自然而然交换两节点的数据域（值val）我们就可以删除要删除的节点了。
我觉得这个题主要考察对单链表的熟悉程度，我们知道，要删除单链表中的一个节点，就必须知道该节点前面的一个节点，这样才能正确删除。

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    //1.先与其后面一节点交换值
    node->val = node->next->val;

    //2.删除与其交换值的后面那个节点。
    struct ListNode * tmp = node->next; //记录要删除节点的地址，为free删除准备
    node->next = node->next->next;

    free(tmp);
    tmp = NULL;

    return 0;
}
```
