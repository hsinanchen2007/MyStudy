```
//直接用数组模拟队列，可灵活操作。其中，head为队列头的下一个位置。
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    TreeNode* que[9999];
    int head = 0, tail = 0;
    que[head++] = root;
    vector<vector<int>>ans;
    if(root == NULL) return ans;
    while(tail != head){
        int _head = head;
        vector<int>vec;
        for(int i = tail; i < _head; i++){
            vec.push_back(que[i]->val);
            if(que[i]->left)
                que[head++] = que[i]->left;
            if(que[i]->right)
                que[head++] = que[i]->right;
        }
        ans.push_back(vec);
        tail = _head;
    }
    int n = ans.size();
    for(int i = 0; i < n/2; i++){
        swap(ans[i], ans[n-i-1]);
    }
    return ans;
}
```
