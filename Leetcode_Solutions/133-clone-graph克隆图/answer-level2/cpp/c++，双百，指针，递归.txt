### 解题思路
主要思想是通过递归，创建和更新新的图节点。抱歉之前没写注释，没想到大家会看哈哈哈

### 代码

```cpp
class Solution {
public:
    Node* used[101];           //创建一个节点（指针）数组记录每个拷贝过的节点
    Node* cloneGraph(Node* node) {
        if(!node)return node;   //如果是空指针，则返回空
        if(used[node->val])return used[node->val];  //该节点已经拷贝，直接返回该节点的指针即可
        Node* p=new Node(node->val);    //创建拷贝节点
        used[node->val]=p;             //递归会遍历每一个原有节点，然后将拷贝后的指针放入used
        vector<Node*> tp=node->neighbors;
        for(int i=0;i<tp.size();i++) //将该节点的邻接节点放入拷贝节点邻接数组
        p->neighbors.push_back(cloneGraph(tp[i]));//递归实现每一个节点的更新
        return p;           //返回拷贝后的节点
    }
};
```