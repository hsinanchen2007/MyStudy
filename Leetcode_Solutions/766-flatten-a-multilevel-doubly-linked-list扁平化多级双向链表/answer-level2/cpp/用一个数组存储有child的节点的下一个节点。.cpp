### 解题思路
一直遍历节点，直到遇到有child的节点。就把它的下一个节点保存在vector中。一定要把child指针废了。使它指向nullptr
再反向取vector里的链表，把它们依次连接在后面。
最后别忘记指向nullptr


这么一说突然感觉可以用一个栈来做。。  压入后取出来。。

### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    // 执行用时 :8 ms, 在所有 C++ 提交中击败了62.16% 的用户
    // 内存消耗 :7.5 MB, 在所有 C++ 提交中击败了100.00%的用户
    Node* flatten(Node* head) {
        if(!head) return head;
        Node* pNode = head;
        Node* pNext = nullptr;
        vector<Node*> vec;//使用vector向量存储每个有child节点的节点的下一个节点。
        while(pNode){
            if(pNode->child){//把和child相连的指针变成next,prev指针。
                vec.push_back(pNode->next);
                pNext = pNode->child;
                pNode->next = pNext;
                pNext->prev = pNode;
                pNode->child = nullptr;//题目要求没有child指针了。
            }
            if(!pNode->next) break;
            pNode = pNode->next;
        }
        for(int i = vec.size()-1;i>=0;--i){
            if(vec[i]){//确保vec里面的链表不为空。连接NEXT,PREV节点。
                pNode->next = vec[i];
                vec[i]->prev = pNode;
            }
            while(pNode->next){
                pNode = pNode->next;
            }
        }
        pNode->next = nullptr;// 最后要把尾节点连上NULL
        return head;
    }


};
```