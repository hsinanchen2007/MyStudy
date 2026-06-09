
## 形式一：

### 一：后序
                               8
                        3             4
                    5       4

定义：
res:放后序结点值val；
node：放未访问过的结点，这里的未访问指的是其val还没存入res;
visited:保存已访问过的结点，访问过指的是其val已存入res;

1.对于上面的树，入栈顺序：8->4->3->4->5,出栈顺序：5->4->3->4->8.即我们在使用栈存结点时，为了满足后序的顺序，每次是先入右结点，后入左结点，因为这样出栈时就是左，右，中。
2.如果一个结点的孩子不是null且没被访问过就入栈
3.如果一个结点的左右孩子是null或被访问过，那么就把其val放入res,别出栈，并加入visited.

### 代码

```cpp
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root){
    vector<int>res;
    stack<TreeNode*>node;
    unordered_set<TreeNode*>visited;
    if(root)node.push(root);//后序遍历先把root入栈，因为先入先出,root最后访问val
    TreeNode *temp;

    while(!node.empty()){
        temp=node.top();
        bool leftVisit=true,rightVisit=true;
        if(temp->right&&visited.find(temp->right)==visited.end()){//先入后出，第二入右孩子，第三入左孩子
            rightVisit=false;
            node.push(temp->right);
        }
        if(temp->left&&visited.find(temp->left)==visited.end()){
            leftVisit=false;
            node.push(temp->left);
        }
        if(leftVisit&&rightVisit){//一个结点的左右孩子都访问过或为空，那么就输出其val,因为是后序
            res.push_back(temp->val);
            visited.insert(temp);//已访问val的结点放入visited
            node.pop();//已访问过val的结点失去价值，出队

        }
    }
    return res;
}
};
```

### 二：前序
                               8
                        3             4
                    5        0
1.不同于后序，后序想要输出当前的结点之前需要判断左右孩子是否已经输出，而前序一进来直接输出当前结点值。
2.一输出结点值，就将该结点出栈，因为已经失去价值。

```

class Solution {
public:

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        stack<TreeNode*>node;
        unordered_set<TreeNode*>visited;
        TreeNode* temp;
        if(root)node.push(root);

        while(!node.empty()){
            temp=node.top();
            node.pop();
            res.push_back(temp->val);
            visited.insert(temp);

            if(temp->right&&visited.find(temp->left)==visited.end()){//右结点先入栈后输出
                node.push(temp->right);
            }
            if(temp->left&&visited.find(temp->left)==visited.end()){
                node.push(temp->left);
            }
        }
        return res;
    }

};
```

### 中序
中序遍历如果采用上面相同方法有点麻烦，因为每次每个右结点都要在其根结点之前入栈，但当每个入栈结点成为新的根结点时就相当于在右孩子之前入栈了。所以要特殊处理。

```

class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        vector<TreeNode*>node;//采用vector代替stack，因为要查看某结点是否已在node中
        unordered_set<TreeNode*>visited;
        TreeNode* temp,*rightOne;

        if(root)node.push_back(root);

        while(!node.empty()){
            temp=node.back();
            //在处理temp时，右结点不可能已经被visit了，但是可能以入栈或没入栈
            if(temp->right&&find(node.begin(),node.end(),temp->right)==node.end()){
                //先把根结点出栈，把右孩子先放进去，再根结点入栈，这样保持了之后回溯时根结点早于右孩子被访问。
                node.pop_back();
                node.push_back(temp->right);
                node.push_back(temp);
            }

            if(!temp->left||visited.find(temp->left)!=visited.end()){//左边为空或已输出过
                res.push_back(temp->val);
                node.pop_back();
                visited.insert(temp);
            }
            //在处理temp时，左节点有可能被visit了(回溯时),也可能没被visit(往下时）
            if(temp->left&&visited.find(temp->left)==visited.end()){
                node.push_back(temp->left);
            }
        }
        return res;
    }
};
```


## 形式二：更好的方式！模拟递归式

1.中序
```
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode*>node;
        vector<int>res;
        TreeNode* temp=root;
        while(temp||!node.empty()){
            if(temp){//如果当前结点不空，直接入栈
                node.push_back(temp);
                temp=temp->left;//和dfs类似，继续深入，temp改为左子树，这符合中序顺序
            }
            else{//temp=null，说明到达递归边界，我们回溯，栈顶元素出栈输出，这符合中序顺序
                temp=node.back();
                node.pop_back();
                res.push_back(temp->val);
                //回溯到上一层后沿着右孩子继续dfs
                temp=temp->right;
            }
        }
        return res;

    }
};
```


2.前序
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode*>node;
        vector<int>res;
        TreeNode* temp=root;
        while(temp||!node.empty()){
            if(temp){
                res.push_back(temp->val);//直接输出
                node.push_back(temp);
                temp=temp->left;
            }
            else{
                temp=node.back();
                node.pop_back();
                temp=temp->right;
            }
        }
        return res;

    }
};

3.后序

法1：加上一个集合visited判断右结点是否已经访问过
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root){
        vector<int>res;
        stack<TreeNode*>node;
        TreeNode *temp=root;
        unordered_set<TreeNode*>visited;
        while(temp||!node.empty()){
           if(temp){
            //    cout<<'a'<<endl;
               node.push(temp);
               temp=temp->left;
           }
           else{
               temp=node.top();
               //只有右结点已输出或已空才输出当前结点值
               if(!temp->right||visited.find(temp->right)!=visited.end()){
                   res.push_back(temp->val);
                   node.pop();//pop出val已输出的结点
                   visited.insert(temp);//表明该节点已访问，中间结点输出时用于判断右孩子有没有输出
                   temp=NULL;
               }
               else{temp=temp->right;}
           }

        }
        return res;
    }
};


法二：一个二叉树的镜像二叉树的前序的逆序等于原二叉树的后序
原：                                           镜像：
                               8                              8
                        3            4                 4            3
                    5       4                                  4         5


原二叉树的后序：54348
镜像二叉树的前序：84345
故先求镜像二叉树的前序再reverse,而求镜像二叉树的前序并不需要重构一个镜像二叉树，而是直接使用原二叉树，但遍历左右子节点的顺序为先右后左。
