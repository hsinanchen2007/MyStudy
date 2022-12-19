### 解题思路
一开始以为就是一个拷贝图，但是一直报错 Node with value 2 was not copied but a reference to the original。
后来看了一些题解原来是深拷贝和浅拷贝的区别。也看了一些博文，百度的良莠不齐，包括CSDN。
深拷贝和浅拷贝在基本数据类型上是没有什么区别的，比如int a = 3。学过计组的人应该知道在计算机中以32位补码存在。那么克隆过程，就是开辟一个
新的地址，放上同样的补码。但是在引用或者指针类型变量上，深拷贝和浅拷贝是有区别的。
struct node{
     int a;
     node* next。
} node1;
对node1进行浅拷贝或者深拷贝，都是换一个房子，需要开辟一个内存空间，但是这里面放的next变量是有区别的，浅拷贝就是原来的next，但是
深拷贝是next指向结点后克隆结点的地址。

### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    map<Node*,Node*>mp;
    //Node* cur;
    Node* cloneGraph(Node* node) {
        // 对当前节点进行克隆，走到下一个节点。
        if(!node) return NULL;

        
        Node* cur = new Node(node->val);  //Node with value 2 was not copied but a reference to the original 
        //one.这是报错。

 
        mp[node]=cur;

        for(int i=0;i<node->neighbors.size();i++){
            if(mp.find(node->neighbors[i])==mp.end()){ // 当前节点没有被访问过
                cloneGraph(node->neighbors[i]);
                cur->neighbors.push_back(mp[node->neighbors[i]]);
                
            }else{  // 如果当前节点的邻居已经被创建，那么显然不需要递归，只需要压入新节点的地址即可，即深拷贝。
                cur->neighbors.push_back(mp[node->neighbors[i]]);
            }
        }
        return cur;

    }
 


};
```