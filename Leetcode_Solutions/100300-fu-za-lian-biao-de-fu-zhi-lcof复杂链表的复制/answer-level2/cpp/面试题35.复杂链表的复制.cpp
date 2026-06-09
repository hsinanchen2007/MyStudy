### 解题思路
核心要点：利用C++hashmap进行链表的生成和指针的导向
执行用时 :20 ms, 在所有 C++ 提交中击败了19.56%的用户
内存消耗 :11.1 MB, 在所有 C++ 提交中击败了100.00%的用户
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
        unordered_map<Node*,Node*>umap;
        for(Node*i=head;i!=NULL;i=i->next){
            umap[i]=new Node(i->val);
        }
        for(Node*i=head;i!=NULL;i=i->next){
            if(i->next!=NULL)umap[i]->next=umap[i->next];
            if(i->random!=NULL)umap[i]->random=umap[i->random];
        }
        return umap[head];
    }
};
```