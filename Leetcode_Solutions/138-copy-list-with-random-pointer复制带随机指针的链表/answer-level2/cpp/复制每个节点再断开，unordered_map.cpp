### 解题思路
这道题剑指offer35题复杂链表的复制一样的。


首先想到的就是先复制一下每个节点再原节点后面，再复制每个指针。最后再断开。
重要的是最后断开的部分。p2->next = p1!=NULL?p1->next:NULL; 要想到p1已经指到null的情况。

第二个方法是哈希表。  把复制的节点存在哈希表中。
重要的是先复制每个节点的值。有了节点。然后再复制next和random指针。最后直接返回harsh[head]就行了。

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

    // 执行用时 :16 ms, 在所有 C++ 提交中击败了47.55% 的用户
    // 内存消耗 :10.9 MB, 在所有 C++ 提交中击败了100.00%的用户
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* pNode1 = head;
        while(pNode1!=NULL){//首先把整个链表节点复制一遍，复制的节点放在原节点后面。
            Node* pCopy = new Node(pNode1->val, pNode1->next, nullptr);
            pNode1->next = pCopy;
            pNode1 = pNode1->next->next;
        }
        Node* pNode2 = head;
        while(pNode2!=NULL){
            if(pNode2->random!=NULL)
                pNode2->next->random = pNode2->random->next;
            pNode2 = pNode2->next->next;
        }
        Node* p1 = head;
        Node* pRes = head->next;
        Node* p2 = pRes;
        while(p1!=NULL){
            p1->next = p1->next->next;
            p1 = p1->next;

            p2->next = p1!=NULL?p1->next:NULL;
            p2 = p2->next;
        }
        return pRes;
    }

    // 执行用时 :16 ms, 在所有 C++ 提交中击败了47.55% 的用户
    // 内存消耗 :11.2 MB, 在所有 C++ 提交中击败了100.00%的用户
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return nullptr;
        unordered_map<Node*, Node*> harsh;
        Node* pNode = head;
        while(pNode){
            harsh[pNode] = new Node(pNode->val);//先要复制节点。  有了节点才能有next和random指针。
            pNode = pNode->next;
        }
        pNode = head;
        while(pNode){
            harsh[pNode]->next = harsh[pNode->next];
            harsh[pNode]->random = harsh[pNode->random];
            pNode = pNode->next;
        }
        return harsh[head];
    }

};
```