参考的一位博主的方法，我觉得很清晰明白！
利用map存储每个节点及其对应的父节点，在对二叉树进行层序遍历的同时向父节点方向遍历。即以target为中心向四周扩散，直到扩散至第K层，找到所有第K层的节点。

```
class Solution {
public:
    void setFather(TreeNode* root,TreeNode* father,map<TreeNode*,TreeNode*>& fatherMap){
        if(root==NULL) return;
        if(father!=NULL) fatherMap.insert({root,father});
        setFather(root->left,root,fatherMap);
        setFather(root->right,root,fatherMap);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        map<TreeNode*,TreeNode*> fatherMap; //用一个map存放每个节点及其对应的父节点
        setFather(root,NULL,fatherMap);  //设置每个节点的父节点
        queue<TreeNode*> q;  //层序遍历/广度优先搜索
        set<TreeNode*> s;  //存放已经访问过的节点
        q.push(target);  //以target为起点扩散搜索距离它K的节点
        s.insert(target);
        while(!q.empty() && K){
            K--;
            int num = q.size();
            for(int i=0;i<num;i++){
                TreeNode* temp = q.front();
                q.pop();
                //向左右子节点扩散
                if(temp->left!=NULL && s.find(temp->left)==s.end()){
                    q.push(temp->left);
                    s.insert(temp->left);
                }
                if(temp->right!=NULL && s.find(temp->right)==s.end()){
                    q.push(temp->right);
                    s.insert(temp->right);
                }
                //向父节点扩散
                if(fatherMap.count(temp) && s.find(fatherMap[temp])==s.end()){
                    q.push(fatherMap[temp]);
                    s.insert(fatherMap[temp]);  
                }
            }
        }
        vector<int> ans;  //最后队列中剩余的节点既是扩散至第K层的所有节点
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
```

