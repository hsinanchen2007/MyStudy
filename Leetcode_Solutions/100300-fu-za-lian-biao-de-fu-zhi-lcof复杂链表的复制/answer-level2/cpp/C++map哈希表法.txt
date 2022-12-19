### 解题思路
时间复杂度：o(n);空间复杂度o(n)
先建立节点（new申请空间），再把next和random连接起来
1、Node* p=new Node(a->val)
2、Node* res=maps[head];return res;

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
        map<Node*,Node*> maps;
        Node* a=head;
        while(a!=nullptr)//建立节点
        {
            Node* p=new Node(a->val);//用a->val给node初始化（为什么不用a？
            maps[a]=p;//key-val：
            a=a->next;
        }
        Node*b=head;
        Node* res=maps[head];//指向map[head]!!!!!!!!!!!
        while(b!=nullptr)
        {
            maps[b]->next=maps[b->next];//next
            maps[b]->random=maps[b->random];
            b=b->next;
        }
        return res;

        
    }
};
```