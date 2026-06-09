### 解题思路
记录一下呀~~

#### 迭代代码

```cpp
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> v;
        if(!root) return v;
        stack<Node*> s;
        s.push(root);
        while(!s.empty()){
            root = s.top();
            s.pop();
            v.push_back(root->val);
            // 添加子节点
            for(int i = root->children.size()-1; i>=0; --i){
                Node* elem = root->children[i];
                if(elem) s.push(elem);
            }
        }
        return v;
    }
private:
    void preorder(Node* root, vector<int>& v){
        if(root){
            v.push_back(root->val);
            for(auto e : root->children){
                preorder(e, v);
            }
        }
    }
};
```

#### 递归代码
```cpp
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> v;
        preorder(root, v);
        return v;
    }

private:
    void preorder(Node* root, vector<int>& v){
        if(root){
            v.push_back(root->val);
            for(auto e : root->children){
                preorder(e, v);
            }
        }
    }
};
```