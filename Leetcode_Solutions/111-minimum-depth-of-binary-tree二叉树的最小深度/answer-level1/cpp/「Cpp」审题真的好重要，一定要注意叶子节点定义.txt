### 解题思路

这道题目容易联想到104题的最大深度，https://leetcode-cn.com/problems/maximum-depth-of-binary-tree

所以一开始我直接把原来的代码照搬过来，把中间求max的函数改成了求min。用案例的数据无压力跑过，然后直接提交，当场被拒。

```cpp
//错误示范, 在碰到[0],[1,2]的时候直接错
class Solution {
public:

    int minDepth(TreeNode* root) {
        if ( root == nullptr){
            return 0;
        }
        int left = minDepth(root->left);
        int right = minDepth(root->right);

        return min(left, right) + 1;
    }

};
```

后来看了一下题解，才明白了最大深度和最小深度有一个很大的区别，最大深度能够保证最后一个节点绝对是叶子节点，而最小深度不行。

因为**定义**说最小深度是从根节点到**最近叶子节点**的最短路径上的节点数量。

官方还温馨的说明了下: 叶子节点是指没有子节点的节点。

因此遇到下面的情况

```bash
    3
   / \
  9  20
 /     \
15      7
```

原来的代码，肯定是返回9和20对应的深度2，而不是15和7对应的深度3.

为了满足题目需求, 需要额外加上一个条件， `(root->left == nullptr || root->right == nullptr)`

也就是判断当前节点是不是叶子节点，如果不是返回的值就是不为0的节点+1，如果是叶子结点就是两者较小的结果加1

```cpp
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if (root->left == nullptr || root->right == nullptr){
            return left == 0 ? right+1 : left +1;
        } else{
            return min(left, right) + 1;
        }

        
        
    }
};
```

![image.png](https://pic.leetcode-cn.com/ffbb9af0447ca78df43b0c33bb1210c0621f09476bc5df96e7e16dd37cb93f7a-image.png)
