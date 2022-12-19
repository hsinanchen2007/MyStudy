**递归：**
参考题解热评2“meteorsh”的解答,比较好理解
思路：
1.如果root==NULL,则返回NULL，其实就是root本身
2.如果p==root||q==root,也返回root,可以和第一点合并为一个
3.然后开始递归 left=isA(root->left,p,q),right=isA(root->right,p,q),如果两边都有返回的值即不为NULL，则说明p,q分布在两边，最近公共祖先是root;如果left==NULL,则说明p,q在右分支，返回right,同理，若right==NULL,则返回left。
```
class Solution {

public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL || p == root || q == root) return root;
		TreeNode* L = lowestCommonAncestor(root->left, p, q);
		TreeNode* R = lowestCommonAncestor(root->right, p, q);
		if (L&&R) return root;
		else if (L == NULL) return R;
		else return L;
	}
};
```
**迭代-父指针**
使用父指针迭代（思路同官方解答方法二--C++版）
1.从根节点开始,若root==NULL||root==p||root==q，return root;否则将root压栈
2.出栈，若其存在左右节点，则以点对形式存入vector v中<子节点，根节点>(以便后期回溯到根节点)，并将左右节点压栈，重复此操作直到栈为空。
2.在vector v中找first为p的点对(注意要从容器尾开始找，方便回溯))，其对应的second即为p的根，再令P=second，继续找，便能找到原p节点的所有祖先，将其放入容器v1中。(回溯，比如<4,7>,<7,root>,若4==p，则说明p的祖先为4,7，root)
3.判断q是否位于v1中，若是，return q;若不是，在vector v中回溯q的祖先，不过不需要向第2步一样push进容器中保存，而是判断其是否位于容器v1中，若是，返回该祖先。
```
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL||root==p||root==q) return root;
        vector<pair<TreeNode*,TreeNode*>>v;
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            TreeNode* t=s.top();
            s.pop();
            if(t->left){ //如果左子节点存在，就压栈，并将点对push进容器
                s.push(t->left);
                pair<TreeNode*,TreeNode*>pl;
                pl.first=t->left;
                pl.second=t;
                v.push_back(pl);
            }
            if(t->right){
                s.push(t->right);
                pair<TreeNode*,TreeNode*>pr;
                pr.first=t->right;
                pr.second=t;
                v.push_back(pr);
            }
        }
        vector<TreeNode*>v1;//用于存放p的所有祖先(包括其本身)
        v1.push_back(p);
        int len=v.size();

        for(int i=len-1;i>=0;i--){//要从容器尾开始回溯
            if(v[i].first==p){
                v1.push_back(v[i].second);//p对应的父节点push进v1；
                p=v[i].second;

            }
        }//将p的所有父节点放入v1中
        int len1=v1.size();
        for(int j=0;j<len1;j++){
            if(v1[j]==q)
                return q;
        }//判断q是否位于v1中，即q是否为p的祖先，若是，直接返回q。

        for(int k=len-1;k>=0;k--){
            if(v[k].first==q){
                q=v[k].second;
                for(int m=0;m<len1;m++){
                    if(q==v1[m])
                        return q;
                }
            }          
        }//返回第一次出现在p的祖先中的q的祖先（即最近公共祖先）
        return NULL;
    }
};


```

