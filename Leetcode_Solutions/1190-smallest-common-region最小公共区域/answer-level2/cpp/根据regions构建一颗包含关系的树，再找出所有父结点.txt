首先根据输入构建**一棵树**，第一个区域作为父结点，剩余的区域作为子节点。

树结点定义如下：

```cpp
class Node {
    public:
        const string& val;      //区域名称
        vector<Node*> sons;     //子节点地址
        Node* father;           //父结点地址

        Node(const string& nval):val(nval),father(nullptr) {
            sons.clear();
        }
};
```


构建树的过程分以下几步：

1. 判断当前区域是否已经存在，使用一个**map**来存储，key值为**区域名称**，value值为当前区域在树中的**结点地址**
2. 如果不村在，需要先新建该结点
3. 然后将后面的结点添加为该结点的子节点

```cpp
    map<string, Node*> rgmap;

    void buildTree(vector<string>& rg) {
        int cnt = rg.size();
        auto it = rgmap.find(rg[0]);
        Node* father;

        if (it != rgmap.end()) {
            father = it->second;
        } else {
            father = new Node(rg[0]);
            rgmap.insert(pair<string, Node*>(rg[0], father));
        }


        for (int i = 1; i < cnt; i++) {
            Node *nnode = new Node(rg[i]);
            rgmap.insert(pair<string, Node*>(rg[i], nnode));
            father->sons.push_back(nnode);
            nnode->father = father;
        }
    }
```

构建完成后，首先处理第一个待查询区域，将它本身及其父结点依次存入数组s。接着从第二个待查询区域本身开始，依次查找s中是否存在该区域，当找到第一个存在的区域时，就是最小的公共区域。

**注意：**如果**A包含B**，那么A和B的**最小公共区域是A**