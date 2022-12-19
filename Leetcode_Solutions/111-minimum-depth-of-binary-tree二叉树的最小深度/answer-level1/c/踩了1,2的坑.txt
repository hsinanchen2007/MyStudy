### 解题思路
本来以为这个题和求最大深度类似，只需要改个条件就行了，没想到踩了一个坑
![QQ截图20200105101710.png](https://pic.leetcode-cn.com/25569660744e8200b56eaf50858ad42a270d92d1d9f91054e301fcf6bb647880-QQ%E6%88%AA%E5%9B%BE20200105101710.png)
先前错误的理解代码：
```
class Solution {
public:
    int minDepth(TreeNode* root) {
        int L=0,R=0;
        if(root == NULL)
            return 0;
        else
        {    
            L = minDepth(root->left);
            R = minDepth(root->right);
            return (L<R?L:R)+1;
        }
    }
};

```

在输入样例为[1,2]的时候，按照之前对题意的理解，生成的是一颗单支树 ，结果应该是这左右子树较小的那一颗的高度+1，但是这里预期输出却是2，题意应该是要求在这种情况下，单支树的最小高度应该是这颗树的高度，而不是空子树的高度＋1,因此作出调整，最后返回的时候，判断若其中一个空0，即出现单支树的情况，树的最小高度为L+R+1，这里因为有一颗子树为空，因此L+R+1实际上是求得单支树的高度加根结点，若不为空就返回两子树中较矮的一棵树的高度+1；


### 代码

```cpp
class Solution {
public:
    int minDepth(TreeNode* root) {
        int L=0,R=0;
        if(root == NULL)
            return 0;
        else
        {    
            L = minDepth(root->left);
            R = minDepth(root->right);
            return (L!=0&&R!=0)?(L<R?L:R)+1:L+R+1;
        }
    }
};
```
