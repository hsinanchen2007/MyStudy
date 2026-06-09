### 分析

![图片.png](https://pic.leetcode-cn.com/c7bd00d5c32300670c911342331c66559358c7e3325a09081d32782be479ddd0-%E5%9B%BE%E7%89%87.png)

1. 二叉树结构特点：一个节点，上面被一个父节点连接，下面连接左右两个子节点

2. 二叉树中路径特点：一个节点，途径这个节点只有 “来” 和 “去” 两个方向

3. 求二叉树中路径的问题，本质上就是一个三选二问题
```
    a
   / \
  b   c
```
    31. 「左中右」，b + a + c
    32. 「左」，b + a
    33. 「右」，c + a


### 套路
1. 二叉树中递归特点
    * 因为数据结构特点，一个节点可以直接访问它的左右子节点，如果只看数据结构，似乎只能从上到下访问
    * 但是配合递归，可以实现：从上方进入，到下，再从下返回（后序遍历）

![图片.png](https://pic.leetcode-cn.com/6d65c2b0072467f4f8eee7605e39fb4f888b317b234dec822be83e718b191db2-%E5%9B%BE%E7%89%87.png)

2. 因此，我们可以由下往上考虑问题
    > 递归思考方式：找一个最下层的二叉树单元，考虑要做的逻辑，然后得出返回值，往上走一层，使用同样的逻辑再验证一下
    * 我们自底向上出发，左右子节点可以比较判断，选择其中一个，然后继续向上（「左」「右」）
    * 或者，不向上，调转方向，连接左右子节点（「左中右」）

<![图片.png](https://pic.leetcode-cn.com/b9217a60716ebc0409c23e92119cbc1f0e3edcea3902c2f353dd9e19f825a6f4-%E5%9B%BE%E7%89%87.png),![图片.png](https://pic.leetcode-cn.com/0f83639c445f4e1eca7708b651590ccb6c1b0d9eb7ad919920953e5b0aa8ce57-%E5%9B%BE%E7%89%87.png),![图片.png](https://pic.leetcode-cn.com/b4daa811d9be57552f69e5011b558534e90ce2a3590fb2763003f3e6eedf27eb-%E5%9B%BE%E7%89%87.png)>


3. 其中「左」「右」使用递归的返回值即可传递，「左中右」需要一个全局变量

4. 逻辑
    41. `if (root == nullptr) return 0;` 递归的出口，`nullptr` 时，根据题意返回，一般都是返回 0
    42. `left = 递归();`
    43. `right = 递归();`
    44. 拿到左右子节点的返回值之后，根据题意做做计算
    45. 如果有全局变量，更新一下
    46. 返回返回值

### 思路
1. 题目中的直径相当于起点和终点是叶子节点的路径长度

2. 考虑叶子节点路径为 0 ，然后每往上一步，长度 + 1 ， 那么「左」「右」情况，就是左右节点递归返回值 + 1

3. 「左中右」的情况就是 左 + 右

### 答题
```cpp
int diameterOfBinaryTree(TreeNode* root, int& ans)
{
    if (root == nullptr) return 0;
    int left = diameterOfBinaryTree(root->left, ans);
    int right = diameterOfBinaryTree(root->right, ans);
    ans = max(ans, left + right);
    return max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode* root) 
{
    int ans = 0;
    diameterOfBinaryTree(root, ans);
    return ans;
}
```

### 其它
同样套路的题目：  
[687. 最长同值路径](https://leetcode-cn.com/problems/longest-univalue-path/) [题解](https://leetcode-cn.com/problems/longest-univalue-path/solution/687-by-ikaruga/)  

[124. 二叉树中的最大路径和](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/)  [题解](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/solution/er-cha-shu-zhong-de-zui-da-lu-jing-he-by-ikaruga/)  


### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

