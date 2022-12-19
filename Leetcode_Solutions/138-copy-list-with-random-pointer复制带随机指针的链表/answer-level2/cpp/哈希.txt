### 解题思路
哈希    使用空间复杂度换取时间复杂度

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
    //要求返回深拷贝，这个时候就需要重新创建链表节点
    //哈希  使用空间复杂度换取时间复杂度    O(n)
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return head;
        Node* pNode = head;
        map<Node*,Node*> sol;
        sol.clear();
        Node* pre = nullptr;
        Node* newhead = nullptr;
        while(pNode!=nullptr)
        {
            Node* now = new Node(pNode->val);
            if(pre!=nullptr) pre->next = now;
            pre = now;
            if(newhead==nullptr) newhead = now;
            sol.insert(make_pair(pNode,now));
            pNode = pNode->next;
        }
        //添加random指针
        pNode = head;
        Node* new_pNode = newhead;
        while(pNode!=nullptr)
        {
            if(pNode->random!=nullptr) {
                new_pNode->random = sol[pNode->random];
            }
            pNode = pNode->next;
            new_pNode = new_pNode->next;
        }
        return newhead;
    }
};
```