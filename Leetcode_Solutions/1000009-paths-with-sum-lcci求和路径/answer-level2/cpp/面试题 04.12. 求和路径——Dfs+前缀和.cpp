前缀和：通过一次减法，求解任意长序列元素的和
回溯：注意消除本次遍历的痕迹，避免影响其他分支。
```
class Solution {
private:
    int target;
    int Dfs(TreeNode* root,int presum,map<int,int> &m){
        if(root==nullptr){
            return 0;
        }
        int res=0;
        presum+=root->val;

        if(m.find(presum-target)!=m.end()){
            res+=m[presum-target];
        } 

        if(m.find(presum)==m.end()){
            m[presum]=1;
        }else{
            m[presum]++;
        }

        res+=Dfs(root->left,presum,m);
        res+=Dfs(root->right,presum,m);
        m[presum]--;
        return res;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        target=sum;
        map<int,int> m;
        m[0]=1;
        return Dfs(root,0,m);
    }
};
```
