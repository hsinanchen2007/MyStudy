采用两种方法：
1. 采用map，时间复杂度为O(n),空间复杂度为O(n)
2. 遍历，时间复杂度O(n),空间复杂度O(1)


```
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
        //方法1：利用哈希表map：时间复杂度O(n)，空间复杂度O(n)

        if(head == nullptr)
            return nullptr;
            
        //创建map对象，并将深度复制的节点添加到map中
        unordered_map<Node*,Node*> newHead;
        Node *pNode = head;
        while(pNode != nullptr)
        {
            newHead[pNode] = new Node(pNode->val);//添加键值对
            pNode = pNode->next;
        }
        
        //添加next/random指针
        pNode = head;
        while(pNode != nullptr)
        {
            newHead[pNode]->next = newHead[pNode->next];
            newHead[pNode]->random = newHead[pNode->random];
            pNode = pNode->next;
        }
        return newHead[head];

        if(head == nullptr)
            return nullptr;

     /* //方法2：时间复杂度O(n),空间复杂度O(1）
        //以下是至少有一个节点的情况
        //复制节点
        Node *pNode = head;
        while(pNode != nullptr)
        {
            Node *pNext = pNode->next;
            //创建新节点
            Node *newNode = new Node(pNode->val);
            //newNode->val = pNode->val;
            //插入新节点
            pNode->next = newNode;
            newNode->next = pNext;
            pNode = pNext;
        }

        //复制随机指针
        Node *preNode = head;
        while(preNode != nullptr)
        {
            pNode = preNode->next;
            //添加随即指针
            pNode->random = preNode->random == nullptr ? nullptr : preNode->random->next;
            //更新当前处理的节点
            preNode = pNode->next;
        }

        //拆分成两个链表
        preNode = head;
        Node *newHead = preNode->next;
        while(preNode != nullptr)
        {
            pNode = preNode->next;

            preNode->next = pNode->next;
            preNode = preNode->next;

            pNode->next =  preNode == nullptr ? nullptr : preNode->next;
        }
        return newHead;
        */
    }
};
```
