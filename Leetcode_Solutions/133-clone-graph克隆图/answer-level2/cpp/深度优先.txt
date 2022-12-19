### 解题思路
深度优先
![微信截图_20200317103013.png](https://pic.leetcode-cn.com/8f690767f4657eab95b948935316836e0c83510502938638878058392e7a90d3-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200317103013.png)


### 代码

```cpp
class Solution {
private:
    set<int> s;
    map<int,Node*> m;
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        if(s.count(node->val))
            return m[node->val];
        Node* t=new Node(node->val);
        m.insert({node->val,t});
        s.insert(node->val);
        for(auto nei:node->neighbors)
        {
            t->neighbors.push_back(cloneGraph(nei));
        }
        return t;
    }
};
```