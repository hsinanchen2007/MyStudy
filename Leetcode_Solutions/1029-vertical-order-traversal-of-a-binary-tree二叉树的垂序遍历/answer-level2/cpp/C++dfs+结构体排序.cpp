### 解题思路
利用dfs得到每一个点的坐标x和y。将坐标信息和点的值存放到结构体当中，再按题目要求进行排序输出即可。题目不难，不要被花里胡哨的说法所干扰。
### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

     struct node{
        int v;
        int x;
        int y;
        node(int vv,int xx,int yy){
            v = vv;
            x = xx;
            y = yy;
        }
    };
    bool cmp(const node& a,const node& b){
        if(a.x != b.x){
            return a.x <b.x;
        }else if(a.y != b.y){
            return a.y > b.y;
        }else{
            return a.v < b.v;
        }
    }
class Solution {
public:

    vector<node> v;
    void dfs(TreeNode* root,int x,int y){
        if(root != NULL){
            v.push_back(node{root->val,x,y});
            dfs(root->left,x-1,y-1);
            dfs(root->right,x+1,y-1);
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,0,0);
        sort(v.begin(),v.end(),cmp);
        int prex = v[0].x;
        vector<vector<int>> ans;
        vector<int>tmp;
        for(int i=0;i<v.size();i++){
            cout<<v[i].v<<'\t'<<v[i].x<<'\t'<<v[i].y<<endl;
            //x的值相同，放入同一个vector中
            if(v[i].x == prex){
                cout<<"prex="<<prex<<'\t'<<v[i].v<<endl;
                tmp.push_back(v[i].v);
            }else{
                ans.push_back(tmp);
                prex = v[i].x;
                tmp.clear();
                tmp.push_back(v[i].v);
            }
        }
        ans.push_back(tmp);//最后一个放入
        return ans;
    }
};
```