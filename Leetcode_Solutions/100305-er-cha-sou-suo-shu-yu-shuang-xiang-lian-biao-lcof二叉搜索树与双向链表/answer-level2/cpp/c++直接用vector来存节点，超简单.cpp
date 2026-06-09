### 解题思路
中序遍历把节点存进vector，然后用vector直接连就可以了，我真他娘是个人才

### 代码

```cpp

class Solution {
public:
    vector<Node*> arr;
    void help(Node* root)
    {
        if(root==NULL)return;
        help(root->left);
        arr.push_back(root);
        help(root->right);
    }
    Node* treeToDoublyList(Node* root) {
        if(root==NULL)return NULL;
        help(root);
        for(int i=0;i<arr.size()-1;i++)
        {
            arr[i]->right=arr[i+1];
            arr[i+1]->left=arr[i];
        }
        arr[arr.size()-1]->right=arr[0];
        arr[0]->left=arr[arr.size()-1];
        return arr[0];
    }
};
```