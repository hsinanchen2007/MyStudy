#### 解题思路：

##### 题目分析：

> **前序遍历特点：** 节点按照 `[ 根节点 | 左子树 | 右子树 ]` 排序，以题目示例为例：`[ 3 | 9 | 20 15 7 ]`
> **中序遍历特点：** 节点按照 `[ 左子树 | 根节点 | 右子树 ]` 排序，以题目示例为例：`[ 9 | 3 | 15 20 7 ]`
> 根据题目描述`输入的前序遍历和中序遍历的结果中都不含重复的数字`，其表明树中每个节点值都是唯一的。

- 根据以上特点，可以按顺序完成以下工作：
  1. 前序遍历的首个元素即为根节点 `root` 的值；
  2. 在中序遍历中搜索根节点 `root` 的索引 ，可将中序遍历划分为 `[ 左子树 | 根节点 | 右子树 ]` 。
  3. 根据中序遍历中的左（右）子树的节点数量，可将前序遍历划分为 `[ 根节点 | 左子树 | 右子树 ] ` 。

- 自此可确定 **三个节点的关系** ：1.树的根节点、2.左子树根节点、3.右子树根节点（即前序遍历中左（右）子树的首个元素）。

> **子树特点：** 子树的前序和中序遍历仍符合以上特点，以题目示例的右子树为例：前序遍历：`[20 | 15 | 7]`，中序遍历 `[ 15 | 20 | 7 ]` 。

- 根据子树特点，我们可以通过同样的方法对左（右）子树进行划分，**每轮可确认三个节点的关系** 。此递推性质让我们联想到用 **递归方法** 处理。

##### **递归解析：**

- **递推参数：** 前序遍历中根节点的索引`pre_root`、中序遍历左边界`in_left`、中序遍历右边界`in_right`。
- **终止条件：** 当 `in_left > in_right` ，子树中序遍历为空，说明已经越过叶子节点，此时返回 $null$ 。
- **递推工作：**
  1. **建立根节点`root`：** 值为前序遍历中索引为`pre_root`的节点值。
  2. **搜索根节点`root`在中序遍历的索引`i`：** 为了提升搜索效率，本题解使用哈希表 `dic` 预存储中序遍历的值与索引的映射关系，每次搜索的时间复杂度为 $O(1)$。
  3. **构建根节点`root`的左子树和右子树：** 通过调用 `recur()` 方法开启下一层递归。
     - **左子树：** 根节点索引为 `pre_root + 1` ，中序遍历的左右边界分别为 `in_left` 和 `i - 1`。
     - **右子树：** 根节点索引为 `i - in_left + pre_root + 1`（即：根节点索引 + 左子树长度 + 1），中序遍历的左右边界分别为 `i + 1` 和  `in_right`。
- **返回值：** 返回 `root`，含义是当前递归层级建立的根节点 `root` 为上一递归层级的根节点的左或右子节点。

> 以下图解展示了题目示例树的建立全流程。

<![Picture1.png](https://pic.leetcode-cn.com/a63028c65f97d4973836bf8c3e9e461b6c753a5669165d8c21268f50a5f4b761-Picture1.png),![Picture10.png](https://pic.leetcode-cn.com/7a6be2049f761d31dd81d9ea21a2bee67d1bd7fbeedd2377735ca834f495fb35-Picture10.png),![Picture11.png](https://pic.leetcode-cn.com/2cce7333f624478c467162caa3dc8f34b96dcaeac3f8b25c51c5609e60fecb83-Picture11.png),![Picture12.png](https://pic.leetcode-cn.com/37ada54821e22257a6d14c475a72e5afbb6ab9488ee7aac1a09c5b10690c532a-Picture12.png),![Picture13.png](https://pic.leetcode-cn.com/d071897e76c77f5a74e2a2e32fb9eca3fe0b14ef077d95d21a42b6f725e98ef3-Picture13.png),![Picture14.png](https://pic.leetcode-cn.com/88187b1c86fde9dd68b53f35d13e94c2d8830f93c621f0c7c753b15f51c40b2b-Picture14.png),![Picture15.png](https://pic.leetcode-cn.com/0a2565b23bafe7e33c744042a2a0cddee4a8eb1fa2e317760e5250847c6b124d-Picture15.png),![Picture16.png](https://pic.leetcode-cn.com/731a07c5d04ead14ef932a0fd1201619d3f7d1940c7077cb0d1cbcf7bfc7131b-Picture16.png),![Picture17.png](https://pic.leetcode-cn.com/baf5ae45712c5f1426df996245c34c31f396111c93ba048a22a0d64045a54004-Picture17.png)>

**复杂度分析**

- **时间复杂度 $O(N)$ ：** $N$ 为树的节点数量。初始化 HashMap 需遍历 `inorder` ，占用 $O(N)$ ；递归共建立 $N$ 个节点，每层递归中的节点建立、搜索操作占用 $O(1)$ ，因此递归占用 $O(N)$ 。（最差情况为所有子树只有左节点，树退化为链表，此时递归深度 $O(N)$ ；平均情况下递归深度 $O(log_2 N)$ ）。

- **空间复杂度 $O(N)$ ：** HashMap 使用 $O(N)$ 额外空间；递归操作中系统需使用 $O(N)$ 额外空间。



```python []
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        self.dic, self.po = {}, preorder
        for i in range(len(inorder)):
            self.dic[inorder[i]] = i
        return self.recur(0, 0, len(inorder) - 1)

    def recur(self, pre_root, in_left, in_right):
        if in_left > in_right: return # 终止条件：中序遍历为空
        root = TreeNode(self.po[pre_root]) # 建立当前子树的根节点
        i = self.dic[self.po[pre_root]]    # 搜索根节点在中序遍历中的索引，从而可对根节点、左子树、右子树完成划分。
        root.left = self.recur(pre_root + 1, in_left, i - 1) # 开启左子树的下层递归
        root.right = self.recur(i - in_left + pre_root + 1, i + 1, in_right) # 开启右子树的下层递归
        return root # 返回根节点，作为上层递归的左（右）子节点
```

```java []
class Solution {
    HashMap<Integer, Integer> dic = new HashMap<>();
    int[] po;
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        po = preorder;
        for(int i = 0; i < inorder.length; i++) 
            dic.put(inorder[i], i);
        return recur(0, 0, inorder.length - 1);
    }
    TreeNode recur(int pre_root, int in_left, int in_right) {
        if(in_left > in_right) return null;
        TreeNode root = new TreeNode(po[pre_root]);
        int i = dic.get(po[pre_root]);
        root.left = recur(pre_root + 1, in_left, i - 1);
        root.right = recur(pre_root + i - in_left + 1, i + 1, in_right);
        return root;
    }
}
```