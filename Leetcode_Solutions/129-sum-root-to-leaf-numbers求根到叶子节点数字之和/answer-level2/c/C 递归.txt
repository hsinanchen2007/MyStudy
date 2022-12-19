
![image.png](https://pic.leetcode-cn.com/b99ab6ba3515dce7bf7f95b51558c6894082a379c3b4fa0db8c736ba00c37ccb-image.png)

```

int count(struct TreeNode *pNode, int Count)
{
    int val = 0;
    int sum = 0;
    val = (Count * 10 + pNode->val);
    if (pNode->left == NULL && pNode->right == NULL) {
        return val;
    }

    if (pNode->left) {
       sum +=  count(pNode->left, val);
    }

    if (pNode->right) {
        sum += count(pNode->right, val);
    }

    return  sum;
}

int sumNumbers(struct TreeNode* root){
    if (root == NULL) {
        return 0;
    }
    return count(root, 0);
}

```