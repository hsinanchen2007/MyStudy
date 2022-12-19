### 解题思路
传入原向量迭代器代替新建向量，节省空间
![image.png](https://pic.leetcode-cn.com/d913de14955167754f796121da170ca83ed1f1c5771fcba9666f59ac0e6c471c-image.png)


### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //递归分治
        return recursionBuild(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
    }

    //递归分治
    TreeNode* recursionBuild(vector<int>::iterator preBegin, vector<int>::iterator preEnd,vector<int>::iterator inBegin, vector<int>::iterator inEnd )
    {
        if(inEnd==inBegin) return NULL;
        TreeNode* cur = new TreeNode(*preBegin);
        auto root = find(inBegin,inEnd,*preBegin);
        cur->left = recursionBuild(preBegin+1,preBegin+1+(root-inBegin),inBegin,root);
        cur->right = recursionBuild(preBegin+1+(root-inBegin),preEnd,root+1,inEnd);
        return cur;
    }
};
```
鉴于有些同学跟我讨论的
`cur->left = recursionBuild(preBegin+1,preBegin+1+(root-inBegin),inBegin,root);`
中第二个参数加不加一的问题，更新了如下解释
其前提是，输入的参数区间是**前闭后开区间**
![image.png](https://pic.leetcode-cn.com/fd3ee58b481dd4222e0cc41f41bec7a1d05fa432b999128a2093367db958c6a3-image.png)

当然，**不加1确实能运行成功，但这是程序的一个bug**:
用上面的例子来说，如果重建左子树时，不加1，那么输入的区间是[1,1)与[0,1)：
1. 那么首先，输入函数的前序区间与中序区间长度是不等的，这逻辑上就不合理
2. 至于为什么能运行成功，是因为以下原因：
- `if(inEnd==inBegin) return NULL;`程序只会判断输入的中序区间前后是否相等而不会检查前序区间
- 因此，上述输入前序区间[1,1)时，虽然区间什么元素都没有但仍然不会停止运行，将继续执行下一`TreeNode* cur = new TreeNode(*preBegin);`
- 这个时候，由于我们传入的是原向量的引用，所以`*preBegin`仍然能正确取到值，即preoder[1]
- 所以程序仍然能够正确运行

所以呢，重建左子树时，第二个参数还是要加一的！
感兴趣的同学不妨在`if(inEnd==inBegin) return NULL;`后加一句`if(preBegin==preEnd) return NULL;`试试，就明白了。
此时，如果不加1，那么将会得到错误答案。