### 解题思路1
迭代：
- 首先理解题意，复制一份链表是要重新开辟一系列结点，存的数值和指向结构都和给定的链表一致。
- 先想到第一步肯定是遍历原链表，创建新结点，存储和给定链表结点一样的值；
- 然后再遍历原链表把next连接好，但是连接random比较麻烦。定位random每次都要从原链表的头结点开始找。
- 所以想到用map存起来，一一对应上。

### C++代码

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
            return NULL;
        unordered_map<Node* ,Node*> m;
        for(Node* it = head;it;it=it->next)
        {
            m[it] = new Node(it->val);
        }
        for(Node* it = head;it;it=it->next)
        {
            if(it->next)
                m[it]->next = m[it->next];
            if(it->random)
                m[it]->random = m[it->random];
        }
        return m[head];
    }
};
```
### 解题思路2
1. 根据原始链表的每个结点N创建对应的N'之后，把N'连接在N的后面。
2. 设置赋值歘来的结点的random。假设原链表上结点N的random指向S，那么复制出来的N'也应该指向S'，也就是S的next。
3. 把长链表拆为两个链表。
tip：
- 步骤2中，要先判断N的random是否为空再决定是否复制，为空则复制的结点也没必要连。
- 步骤3中，要注意判断是否已经到了最后一个点，如果到了就不能再往后复制了，会导致null->next=null的错误。

```
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        Node* pNode = head;
        while(pNode != NULL)
        {
            Node *ClonedNode = new Node(pNode->val);
            ClonedNode->next = pNode->next;
            pNode->next = ClonedNode;
            pNode = ClonedNode->next;
        }
        Node* pNodeRandom = head;
        while(pNodeRandom != NULL)
        {
            if(pNodeRandom->random != NULL)
                pNodeRandom->next->random = pNodeRandom->random->next;
            pNodeRandom = pNodeRandom->next->next;
        }
        Node* originNode = head;
        Node* ColNodeHead = originNode->next;
        while(originNode != NULL)
        {
            Node* ColNode = originNode->next;
            originNode->next = ColNode->next;
            originNode = originNode->next;

            if(originNode == NULL)
                ColNode->next = NULL;
            else
                ColNode->next = originNode->next;
        }
        return ColNodeHead;
    }
```
