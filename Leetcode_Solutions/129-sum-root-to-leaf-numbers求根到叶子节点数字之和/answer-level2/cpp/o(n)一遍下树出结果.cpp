第一次自己写的：击败100%
![image.png](https://pic.leetcode-cn.com/2db6243a0d2bd85949b36f2056aa627a1b82cec2f4b4e6665c10d06a01ad86ec-image.png)
例子：
输入: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
输出: 1026
解释:
从根到叶子节点路径 4->9->5 代表数字 495.
从根到叶子节点路径 4->9->1 代表数字 491.
从根到叶子节点路径 4->0 代表数字 40.
因此，数字总和 = 495 + 491 + 40 = 1026.

思路讲解：分解一下路径 4->9->5 数字演变过程
4 下到 9 得到 49 意味着我们要把4 * 10倍然后传参给 9
然后 49 * 10 = 490 传参给 5 
5 结点是 叶子结点 意味着 495 要加入总结果

```
class Solution {
public:
    int sumNumbers(TreeNode* root) {
      if (root == NULL)
      {
          return 0;
      }
      int retAllCount = 0;
      addAllpathValue(root,0,retAllCount);
      return retAllCount;
    }

    void addAllpathValue(TreeNode* root,int pathCount,int &allCount)
    {
        if (root == NULL)
        {
            return;
        }
        pathCount += root->val;
        if (root->left == NULL && root->right == NULL)
        {
            allCount += pathCount;
            return;
        }

        addAllpathValue(root->left,pathCount * 10,allCount);
        addAllpathValue(root->right,pathCount * 10,allCount);
    }
};
```
