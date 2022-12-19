借助哈希表来存放树的和~ 和递归一样需要后序遍历
时间复杂度为o(n) 空间复杂度也要o(n)
```
代码块
    int findTilt(TreeNode* root) {
        unordered_map<TreeNode*,int> mymap;
        stack<pair<TreeNode*,bool>> s;
        TreeNode* p = root;
        while(!s.empty()|| p!=NULL){
            while(p!=NULL){
                s.push(make_pair(p,false));
                p = p->left;
            }
            pair<TreeNode*,bool>& toppair = s.top();
            if(toppair.second==true){           
                int leftsum = toppair.first->left!=NULL?mymap[toppair.first->left]:0;
                int rightsum = toppair.first->right!=NULL?mymap[toppair.first->right]:0;
                mymap[toppair.first] = leftsum + rightsum + toppair.first->val;
                totalsum += abs(leftsum-rightsum);
                s.pop();
            }else{
                toppair.second = true;
                p = toppair.first->right;
            }
        }
        return totalsum;
    }
```



