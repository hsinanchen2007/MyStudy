
![image.png](https://pic.leetcode-cn.com/f0ea320871c94655f00e9e2061b74ab4f0411d282308e878753a9f4900e9289b-image.png)
想到这个问题，正向理解就可以了。
t要是s 的子树，那么t的头结点一定在s树中
第一步、把s树中和t树头结点相同的节点全部找出来，存到一个数组中。只需要遍历一遍s数组
第二部、将数组中的节点看成单独的树，和t树对比。只要这些节点中所代表的的树和t树相同，就证明，t是s 的子树
```
bool isSameTree(struct TreeNode* s, struct TreeNode* t){
    if(s == NULL && t == NULL) return true;
    if(s == NULL || t == NULL) return false;
    if(s->val != t->val) return false;
    return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
}
void Preorder(struct TreeNode *root, int head, int * index, struct TreeNode** arr)
{
    if(root)
    {
        if(root->val == head) {
            arr[*index] = root;
            ++(*index);
        }
        Preorder(root->left, head, index, arr);
        Preorder(root->right, head, index, arr);
    }
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t){
    struct TreeNode* arr[1024] = {0};
    int index =0;
    Preorder(s,t->val ,&index, arr);
    for(int i = 0; arr[i] != 0; i++)
    {
      if(isSameTree(arr[i], t))  return true;
      
    }
    return false;
}
```
