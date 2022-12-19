## 思路：

**已知条件： 后序序列最后一个值为root；二叉搜索树左子树的值都比root小，右子树的值都比root大。**

**步骤：**
1. 确定根节点root；
2. 遍历序列（除去root结点），找到第一个大于root的位置，则该位置左边为左子树，右边为右子树；
3. 遍历右子树，若发现有小于root的值，则直接返回false；
4. 分别判断左子树和右子树是否仍是二叉搜索树（即递归步骤1、2、3）。

```python []
class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:
        if postorder is None or len(postorder) == 0:
            return True
        n = len(postorder)
        # 根结点
        root = postorder[-1]
        # 在二叉搜索树中左子树的结点小于根结点
        i = 0
        for i in range(n):
            if postorder[i] > root:
                break
        # 在二叉搜索树中右子树的结点小于根结点
        for j in range(i,n-1):
            if postorder[j] < root:
                return False
        # 判断左子树是不是二叉搜索树
        left = True
        if i > 0:
            left = self.verifyPostorder(postorder[:i])  # 左闭右开
        # 判断右子树是不是二叉搜索树
        right = True
        if i < n-1:
            right = self.verifyPostorder(postorder[i:-1])
        return left and right
```
```c++ []
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        bool res = true;
        if (postorder.empty())
            return res;
        res = helper(postorder,0,postorder.size()-1);
        return res;
    }
    bool helper(vector<int>& postorder, int start, int end)
    {
        if (postorder.empty() || start > end)
            return true;
        //根结点
        int root = postorder[end];

        //在二叉搜索树中左子树的结点小于根结点
        int i = start;
        for(;i<end;i++)
        {
            if (postorder[i] > root)
                break;
        }

        //在二叉搜索书中右子树的结点大于根结点
        for(int j = i;j<end;j++)
        {
            if (postorder[j] < root)
                return false;
        }

        //判断左子树是不是二叉搜索树
        bool left = true;
        if (i>start)
        {
            left = helper(postorder,start,i-1);
        }
        //判断右子树是不是二叉搜索树
        bool right = true;
        if (i<end-1)
        {
            right = helper(postorder, i,end-1);
        }
        return left &&  right;
    }
};
```

#### [更多剑指Offer题解（C++与Python实现）](https://github.com/bryceustc/CodingInterviews)
#### [更多LeetCode题解（C++与Python实现）](https://github.com/bryceustc/LeetCode_Note)