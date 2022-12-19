### 解题思路
1.深度优先： 使用两个数组一个保存每层的结点个数，另一个保存每层结点值的和。
vector.size()为无符号类型，如果vector刚定义没添加值则，vector-size()-1报错，因为0是最小的无符号数，再减1则变成最大的无符号数。

2.广度优先
法一：可以选择使用两个队列，一个放当前层结点，另一的暂存所有下一层结点，等当前层的遍历完，此时暂存的下一层成为当前层。
法二：使用一个队列，但结点元素为pair<层数，结点>，这样可以了解某个结点是那一层的，求和时只取层数相同的结点。
### 代码

```cpp
//review
//创建树-前序，这里请教大家一个问题：当结点值范围是整数，如何判断边界条件，即不能用‘#’或‘-1’等当边界条件。
TreeNode* createTree(int &n,int* s){//直接给出结点序列s，当然也可以在函数内部一个一个的输入
    if(s[n]==-1)return NULL;//这里假设均为正整数
    TreeNode *root=new TreeNode;
    root->val=s[n];
    //注意是++n,不是n+1;
    root->left=createTree(++n,s);
    root->right=createTree(++n,s);
    return root;
}

//只给出DFS
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
                vector<double>cnt(1,0);
        vector<int>num(1,0);
        calc(cnt,num,0,root);
        for(int i=0;i<cnt.size();i++){
            cnt[i]/=num[i];
        }
        return cnt;
    }

    void calc(vector<double>&cnt,vector<int>&num,int level,TreeNode*root){
        if(root==NULL)return;
        if(cnt.size()-1<level){
            cnt.push_back(root->val);
            num.push_back(1);
        }
        else{
            cnt[level]+=root->val;
            num[level]+=1;
        }
        calc(cnt,num,level+1,root->left);
        calc(cnt,num,level+1,root->right);
    }
};
```