### 解题思路
刚开始拿到这个题看得人一愣一愣的，还想着这咋只给了一个节点。后来看了评论才明白这题的意思，这个题目是建立在我们已经有了一个链表的基础上，比如我们现在有一个链表类，而这个函数只是一个链表类里面删除一个给定节点的操作也就好理解了。
首先要删除当前节点不能直接delete掉，那样链表就断成两段，所以我们把这个节点的值修改为它下一个节点的值，然后删除下一个节点。由于题目说明这个节点不会是末尾节点，所以它一定有下一个节点，这样就可以达到删除该节点的效果。

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
    void deleteNode(ListNode* node) 
    {
        node->val = node->next->val;  //把值改成下一个节点的值
        ListNode* p = node->next;  
        node->next = p->next;  //逻辑上删除了下一个节点
        delete p;  //释放空间，彻底删除   
    }
};
```