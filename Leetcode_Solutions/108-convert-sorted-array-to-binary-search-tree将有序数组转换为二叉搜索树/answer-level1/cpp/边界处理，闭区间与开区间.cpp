其中序遍历的顺序是有序的，所以根据中序遍历的情况我们可以进行分治，注意左右区间的情况，这种类型的分治，一般采用**左闭右闭取大于mid为中**

左闭右闭
```
TreeNode* build(vector<int>& st,int l,int r)
    {
        if(l>r)//等号不能取
            return NULL;
        int mid=(l+r)/2;
        TreeNode* root=new TreeNode(st[mid]);
        root->left=build(st,l,mid-1);
        root->right=build(st,mid+1,r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums,0,nums.size()-1);
    }
```

左闭右开取=，mid向下取整，mid+1，区间往右挪一位
```
    TreeNode* build(vector<int>& st,int l,int r)
    {
        if(l>=r)//等号必须取到，可以只取等于
            return NULL;
        int mid=(l+r)/2;
        TreeNode* root=new TreeNode(st[mid]);
//区间为[l,mid],[mid+1,r]
        root->left=build(st,l,mid);
        root->right=build(st,mid+1,r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums,0,nums.size());//往后开一位
    }
```
- 左开右闭取=，mid向上取整，mid-1，区间往左挪一位
```
TreeNode* build(vector<int>& st,int l,int r)
    {
        if(l==r)//类似
            return NULL;
        int mid=(r+l+1)/2;//左开向上取整
        TreeNode* root=new TreeNode(st[mid]);
        root->left=build(st,l,mid-1);
        root->right=build(st,mid,r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums,-1,nums.size()-1);//向左一位
    }
```
