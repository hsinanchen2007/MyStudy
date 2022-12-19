### 解题思路
此处撰写解题思路
第一步：把链表的每个节点复制并将它放在原节点后面，只复制next指针；
第二步：如果要找到cur的复制节点的random指针，可以通过cur->random->next找到；
第三步：将原节点和新的节点分类开即可.
### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
    {
        return NULL;
    }
    Node* cur = head;
    Node* tmp = NULL;
    //复制节点并连接每个节点
    while(cur != NULL)
    {
        tmp = cur->next;
        cur->next = new Node(cur->val);
        cur->next->next = tmp;
        cur = tmp;
        //delete Node(cur->val);
    }
    cur = head;
    Node* curCopy = NULL;
    //设置random curCopy
    while(cur != NULL)
    {
        tmp = cur->next->next;
        curCopy = cur->next;
        curCopy->random = (cur->random != NULL) ? cur->random->next : NULL;
        cur = tmp;
    }
    Node* res = head->next;
    cur = head;
    //分离新老链表
    while(cur != NULL)
    {
        tmp = cur->next->next;
        curCopy = cur->next;
        cur->next = tmp;
        curCopy->next = (tmp!= NULL)? tmp->next : NULL;
        cur = tmp;
    }
    return res;
    }
};
```