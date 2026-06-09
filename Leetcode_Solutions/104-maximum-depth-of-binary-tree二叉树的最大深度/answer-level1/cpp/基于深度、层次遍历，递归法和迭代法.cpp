这道题可用DFS和BFS两种算法。

其中，DFS算法的递归形式有一种。这里留意，c++的标准库里是可以直接使用max函数的。
```
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return root==NULL?0:max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};
```
而DFS算法的迭代形式，可分为先序、中序和后序三种。三者都需要借助一个栈，且迭代细节有别。

此处涉及到c++ stl的stack的使用。stack的定义式为：
```
        stack<pair<TreeNode*,int>> s;
```
上述式子表面stack的类型是pair<TreeNode*,int>，而pair类型又是一种stl容器，在实际调用取值时，取pair.first获得第一个元素，取pair.second获得第二个元素。

而stack的方法有push，top和pop。注意，在c++中，pop方法并不会返回栈顶元素，因此实际操作时，先调用top获取栈顶元素，再调用pop将栈顶元素移除。

基于迭代形式的三种遍历方法，在进出栈的操作差异如下：

前序：
迭代前先把树根结点入栈。迭代开始，迭代条件是栈非空。迭代过程中，每移出一个栈顶元素，获取其深度值，并考察其是否有左右子结点。如果有右结点，先压入右结点，然后再考察左结点。子结点的深度即为方才出栈的父结点深度加一。移出栈顶元素时，将结点深度与函数已存最大深度进行对比以更新。
```
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){return 0;}
        // 先序遍历非递归方法
        stack<pair<TreeNode*,int>> s;//定义一个栈
        TreeNode *p = root;//定义一个树结点指针，指向根结点
        int max_deep = 0;//最大深度
        int deep;
        s.push(pair<TreeNode*,int>(p,1));
        while(!s.empty()){
            p = s.top().first;
            deep = s.top().second;
            s.pop();
            if(max_deep<deep) max_deep = deep;
            if(p->right!=NULL) s.push(pair<TreeNode*,int>(p->right,deep+1));
            if(p->left!=NULL) s.push(pair<TreeNode*,int>(p->left,deep+1));
        }
        return max_deep;
    }
};
```

中序：迭代前无需将根结点入栈。迭代条件是栈非空或遍历指针非空。迭代过程中，如果当前遍历指针非空，则将其所指结点压入栈，并将指针指向左结点。若当前指针为空，则将当前栈顶元素出栈，将其深度与当前已存最大深度进行对比以更新。更新后将指针指向其右结点。每当指针易主，都将当前指针结点深度加一。这里有个细节，因为无论是指针指向非空的左结点，亦或是出现移出栈顶结点并指向其右结点，下一个压入栈的结点的深度必然是当前指针所指结点深度加一，因此“深度加一”这一代码只用写一次。
```
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){return 0;}
        // 中序遍历非递归方法第二版
        stack<pair<TreeNode*,int>> s;//定义一个栈
        TreeNode *p = root;//定义一个树结点指针，指向根结点
        int max_deep = 0;//最大深度
        int deep=1;
        while(!s.empty()||p!=NULL){
           if(p){
                s.push(pair<TreeNode*,int>(p,deep));
                p=p->left;
            }//左子树为空
            else{
                 if(!s.empty()){
                    p=s.top().first;
                    deep=s.top().second;
                    s.pop();//这一步切记不可忘
                    if(max_deep<deep) max_deep=deep;
                    p=p->right;
                }
            }
            deep++;
        }
        return max_deep;
    }
};
```
后序：后序与中序相似。迭代前无需压入根结点。迭代条件是栈非空或指针非空。迭代中，当指针非空时，将结点压入栈，将指针指向左结点。若当前指针为空，则考察栈顶结点。若栈顶结点的右结点存在且未曾访问过，则在保留既有栈顶元素的情况下将指针指向其右结点，继续迭代。若栈顶结点没有右结点或右结点已经访问过，则将其移出栈，并将其深度与与已存最大深度进行对比以更新，同时将遍历指针置空。在这里，设置额外的一个指针用以记录上次访问的结点。与中序遍历一样，后序遍历的“深度加一”代码同样只需写一次，但要注意把“deep=s.top().second;”这行代码写在考察栈顶元素处，而不是出栈处，否则无法做到只写一次“深度加一”。
```
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){return 0;}
        // 后序遍历非递归方法
        stack<pair<TreeNode*,int>> s;//定义一个栈
        TreeNode *p = root,*r=NULL;//定义一个树结点指针，指向根结点。定义一个最后访问树结点指针。
        int max_deep = 0;//最大深度
        int deep=1;
        while(!s.empty()||p){
           if(p){
                s.push(pair<TreeNode*,int>(p,deep));
                p=p->left;
            }//左子树为空
            else{
                 if(!s.empty()){
                    p=s.top().first;
                    deep=s.top().second;
                    if(p->right&&p->right!=r){
                        p=p->right;
                    }
                    else{
                        if(max_deep<deep) max_deep=deep;
                        s.pop();
                        r=p;
                        p=NULL;
                    }
                }
            }
            deep++;
        }
        return max_deep;
    }
};
```

BFS算法，在树中实则为层次遍历。与深度遍历不同，层次遍历需要借助一个队列。stl的queue的定义式为：
```
queue<TreeNode*> q;
```
此处queue的类型只是树指针，因为层次遍历求深度不再需要记录每个结点的深度。

层次遍历的大体流程是：迭代前将根结点压入队列。迭代条件是队列非空。迭代过程中，将对首元素出队，并将其子结点从左至右以此压入队列。

层次遍历求深度的关键是判断何时遍历进入下一层，这就需要一个额外的指针，指向当前层的最后一个结点。显然，初始时，层最后结点就是根结点，因此遍历指针和最后结点指针都指向根结点。后序，但凡出现遍历指针结点等于层最后结点时，即可在向队列添加完元素后，将最后指针指向当前队列的最后一个元素，同时深度加一。

注意，此处操作步骤不能颠倒，必须是：队首元素出队-判断是否易层-对首子结点入队-更改层最后结点指针。由于修改最后结点指针必须在子结点入队后进行，因此在判断是否易层时用一个布尔类型的标志位来记录，以便后序判断是否要进行修改最后结点指针的操作。更改最后结点指针后，标志位需要复原。
```
class Solution {
public:
    int maxDepth(TreeNode* root) {
        //层次遍历
        if(root==NULL){return 0;}
        queue<TreeNode*> q;
        TreeNode *p=root;
        TreeNode *r=root;
        int deep=0;
        bool flag = false;
        q.push(p);
        while(!q.empty()){
            p=q.front();
            if(p==r) flag=true;
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
            if(flag){
                r=q.back();
                flag=false;
                deep++;
            }
            q.pop();//不能忘
        }
        return deep;
    }
};
```