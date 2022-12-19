### 解题思路一 顺序查找法
    /*
     * 方法１　顺序查找法　O(n)
     * 设置一个伪节点，将该节点指向头节点，
     * 目的是方便的返回头节点，
     * 当头节点的值与val相等，则删除头节点并返回头节点的下个节点
     * 当不相等，则从头节点的下一个节点head->next开始顺序查询链表，
     * 并将每个节点的值与val进行比较，
     * 如果相等则删除该节点，即head->next = head->next->next
     * */
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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode node(0);
        node.next = head;
    
        if(head->val == val){
            head = head->next;
            return head;
        }
    
        while (head->next){
            if(head->next->val == val){
                head->next = head->next->next;
                // 找到后就不需要继续遍历后面的节点
                // 说明中表示节点不重复
                break;
            }
            head = head->next;
        }

        return node.next;
    }
};
```
### 解题思路二 覆盖法
    /*
     * 方法2 覆盖节点法 O(1)
     * Leetcode的题目与剑指offer原题的描述有差别
     * 原题的函数形参第二个值是ListNode*类型的
     * 当知道要删除的节点时，可以将该节点的后一个节点覆盖原节点，
     * 再将多余的后节点删除就等于删除了该节点
     * */
### 代码
```cpp
ListNode *deleteNode(ListNode *head, ListNode *node) {
    if(!head || !node){
        return nullptr;
    }

    if(head->val == node->val) {
        head = head->next;
        return head;
    }

    //使用下一节点覆盖要删除节点
    node = node->next;
    node->val = node->next->val;

    //删除多余的下一节点
    node->next = node->next->next;

    return head;
}
```