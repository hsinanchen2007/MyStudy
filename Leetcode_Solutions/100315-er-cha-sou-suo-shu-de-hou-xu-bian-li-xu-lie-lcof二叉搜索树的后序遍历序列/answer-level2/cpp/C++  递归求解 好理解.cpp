### 解题思路

### 代码

```cpp
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        //二叉搜索树的后序遍历结果依次是左子树，右子树，根节点
        if(postorder.size()==0)return true;
        int root=postorder[postorder.size()-1];//确定根节点
        vector<int>left;
        vector<int>right;
        int i=0;//i表示左子树起点索引
        for(;i<postorder.size()-1;i++){
            if(postorder[i]<root){
                left.push_back(postorder[i]);
            }
            else break;
        }
        int j=i;//j表示右子树起点索引
        for(;j<postorder.size()-1;j++){
            if(postorder[j]>root)right.push_back(postorder[j]);
            else return false;
        }
        bool flagleft=true;
        bool flagright=true;
        if(i>0)flagleft=verifyPostorder(left);//递归检查左子树
        if(i<postorder.size()-1)flagright=verifyPostorder(right);//递归检查右子树
        return flagright&&flagleft;
    }
};
```