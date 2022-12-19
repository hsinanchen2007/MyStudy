### 解题思路
此处撰写解题思路

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
#include<unordered_map>
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return nullptr;
        unordered_map<Node *, Node *> nodemap;  //哈希表
        //首先将所有节点保存到哈希表
        for(Node *it = head; it; it=it->next)
        {
            nodemap[it] = new Node(it->val);  //深复制每个节点
        }
        //接下来将每个节点的next和random节点保存
        for(Node *it = head; it; it=it->next)
        {
            if(it->next)nodemap[it]->next = nodemap[it->next];  //从nodemap中拿出it->next对应的节点(副本)赋值给nodemap[it]->next
            if(it->random)nodemap[it]->random = nodemap[it->random];
        }
        return nodemap[head];
    }
};
```