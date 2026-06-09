### 解题思路
通过记录有效坐标点，通过数组和长度搞有点晕。

### 代码

```c
struct TreeNode* constructFromPrePostGoon(int* pre, int preStart, int preEnd, 
                                                      int* post, int postStart, int postEnd){
        struct TreeNode* root;
        int i, len;
        if (preStart > preEnd) {
            return NULL;
        }
        root = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
        root->val = pre[preStart];
        if (preStart == preEnd) {
            return root;
        }
        for (i = postStart; i <= postEnd; i++) {
            if (post[i] == pre[preStart + 1]) {
                len = i - postStart + 1;
                break;
            }
        }
        root->left = constructFromPrePostGoon(pre, preStart + 1, preStart + len, 
                                              post, postStart, postStart + len - 1);
        root->right = constructFromPrePostGoon(pre, preStart + len + 1, preEnd, 
                                              post, postStart + len, postEnd - 1);
        return root;
}    
struct TreeNode* constructFromPrePost(int* pre, int preSize, int* post, int postSize){
    return constructFromPrePostGoon(pre, 0, preSize - 1, post, 0, postSize -1);
}
```