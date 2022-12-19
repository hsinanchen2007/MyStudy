### 解题思路
方法一：
1、先通过第一个循环完成对新链表的建立以及将每个节点放入vector，
2、在第二个循环完成对next pointer的连接，同时对于random pointer：关键在于使用一个map映射新旧链表每个节点的对应关系，这样在第二个循环完成对random的连接时简单快捷。
注意：在循环中建立新链表的结点是使用new分配内存空间，否则新建的节点为局部变量，离开循环时即被析构了！！！
new返回的是指针。

方法二：O(1)空间
1、维护一个lastnode和现在的copynode，每次循环建立一个复制的下一个节点，视为当前节点，连接完上一个节点与该节点后，将上一个节点对应源节点的next pointer指向上一个对应的复制节点，这样相当于建立了方法一中的map的对应关系，并且将上一个复制节点的random pointer指向源节点的random pointer的目标
2、这样在第二循环里，只需要将lastcopy->random = lastcopy -> random -> next，就相当于将random指向了对应的复制节点。
*3、但是该方法题目不允许更改原链表，可以开阔一下思路。
### 代码

```cpp

//方法一：
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)return nullptr;
        vector<Node*> nodes;
        map<Node*,Node*> correspondnodes;
        
        Node* origin = head; 
        while ( origin != nullptr){
            Node* copy = new Node(origin->val);
            nodes.push_back(copy);
            correspondnodes[origin] = copy;
            origin =origin->next;
        }

        int len = nodes.size();
        int i = 0;
        origin = head;
        while (origin != nullptr){
            if(i<len-1)nodes[i]->next = nodes[i+1];//小心越界注意i
            if(origin->random != nullptr)nodes[i]->random = correspondnodes[origin->random];
            i++;
            origin =origin->next;
        }
        return nodes[0];
    }
};

//方法二：
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
        if(head == nullptr)return nullptr;
        
        Node* lastorigin = head;
        Node c(head->val);
        Node* copyhead = &c;
        Node* lastcopy = copyhead;
        cout<<lastcopy->val<<" ";
        while ( lastorigin->next != nullptr){
            Node* copy = new Node(lastorigin->next->val);
            Node* temp = lastorigin->next;
            lastorigin -> next = lastcopy;
            
            lastcopy -> next = copy;
            lastcopy -> random = lastorigin -> random;
            
            lastorigin = temp;
            lastcopy = copy;
            cout<<copy->val<<" ";
        }

        lastcopy = copyhead;
        while (lastcopy != nullptr){
            if(lastcopy->random != nullptr){
                lastcopy->random = lastcopy -> random -> next;
            }
            lastcopy = lastcopy -> next;
        }
        return copyhead;
    }
};
```