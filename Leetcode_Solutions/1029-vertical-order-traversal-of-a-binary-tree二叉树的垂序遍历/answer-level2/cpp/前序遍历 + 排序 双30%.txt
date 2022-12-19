第一次写题解，时间和空间效率都不太高，但是个人觉得写的比较好理解，大佬觉得可以优化欢迎指正，勿喷哈

思路是普通的递归进行前序遍历，用map来存储每一列的遍历结果，并且每一个节点存储结果的时候记录一下层数level，方便最后从上到下做一次排序。
```
class Solution {
public:
    map<int,vector<vector<int>>> helper;//我在想这里用双向链表可能快一点，避免map自身的排序，但是写起来可能比较麻烦
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        insert(root,0,0);//root的index为0，且层数为0
        vector<vector<int>> ans;
        map<int,vector<vector<int>>>::iterator iter = helper.begin();
        while(iter != helper.end()){
            vector<vector<int>> temp = iter->second;
            sort(temp.begin(),temp.end());
            vector<int> thisOne;
            for(vector<int> v:temp){
                thisOne.push_back(v[1]);
            }
            ans.push_back(thisOne);
            iter ++;
        }
        return ans;
    }

    void insert(TreeNode* root,int index,int level){
        if(!root){
            return;
        }
        helper[index].push_back({level,root->val});
        insert(root->left,index - 1,level + 1);//左子树的index为当前-1，level为当前+1
        insert(root->right,index + 1,level + 1);//右子树的index为当前+1，level为当前+1
    }
};
```
