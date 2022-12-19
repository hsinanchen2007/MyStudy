![image.png](https://pic.leetcode-cn.com/bfca3eb6b928dce76fbe091abf22036db533aacf8a12c44b6d28dd7f06e7e647-image.png)
  
---
**代码：**
```
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    // 判断只有一边为空情况
    if((p == NULL && q!= NULL) || (p != NULL && q== NULL)) 
        return false;
    // 判断都为空情况，返回 true
    if(p == NULL && q== NULL) 
        return true;

    // 判断值不同情况
    if(p->val != q->val) 
        return false;
    
    // 递归体
    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);
    
    return left && true && right;
}
```
