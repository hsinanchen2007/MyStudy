### 解题思路
看了一下题解，本篇算是层次遍历非递归的优化算法。
因为在右边看，所以只需要新建一个一维整数组，每次把val保存在数组对应层数的位置上，相同层数的在赋值当中一个一个覆盖，层数位置上留下的就是最后覆盖上去的，也就是最右边的了。（因为层数遍历从左到右从上到下，我们要的就是每一层的最右边，也就是最后遍历到的那一个）
思路是在树TreeNode结点加一个保存层数的参数`layer`，组成新结构BTNode，建立BTNode的队列（vector也可以，但是主要涉及插入尾部和取出头部的操作，用队列更符合逻辑），再建立存储val的一维数组（不知道长度所以需要一个保存层数的辅助参数`maxl`）。
最后再把数组转换成vector输出就好啦！

### 代码

```cpp 
class Solution {
public:
vector<int> rightSideView(TreeNode* root) {
    vector<int> anss;//最后需要输出的
    int maxl=0;//最大层数
    int ans[200];//不知道有多少层，先开200
    struct BTNode{
    TreeNode *t;
    int layer;};
    queue<BTNode*> q;
    BTNode* tmp;
    
    if(root){
        BTNode *h=new BTNode;
        h->t=root;
        h->layer=0;
        q.push(h);
        while(!q.empty())
        {
            tmp=q.front();
            q.pop();
            if(tmp)
               ans[tmp->layer]=tmp->t->val;//保存当前节点的值在对应层数，覆盖该结点左边的值
               maxl=tmp->layer+1;
            if(tmp->t->left)//层次遍历
            {
                BTNode* lc= new BTNode;
                lc->t=tmp->t->left;
                lc->layer=tmp->layer+1;
                q.push(lc);
            }
            if(tmp->t->right)
            {
                BTNode* rc=new BTNode;
                rc->t=tmp->t->right;
                rc->layer=tmp->layer+1;
                q.push(rc);
            }
        }
    }
    for(int i=0;i<maxl;i++)
    anss.push_back(ans[i]);
      return anss;
    }
};
```