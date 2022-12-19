### 方法一：直接递归

* 思路：总节点个数 = 左子树节点个数 + 右子树节点个数 + 1
* 时间复杂度: O(N), 空间复杂度: O(logN)

```python []
class Solution:
    def countNodes(self, root: TreeNode) -> int:
        if root is None:
            return 0
        return self.countNodes(root.left) + self.countNodes(root.right) + 1
```

### 方法二：二分递归

* 我理解的二分法的算法是：每一步把问题都拆成两半，然后扔一半留一半。正如方法一拆解的那样：`总节点个数 = 左子树节点个数 + 右子树节点个数 + 1`。但是左右子树都要递归吗？答案是否定的。
* 根据完全二叉树的性质
    * 如果左子树和右子树一样高，那么左子树必然为满二叉树
    * 如果左子树比右子树高，那么右子树必然为满二叉树
* 因此我们只需要计算出满二叉树的节点个数，把另一半继续递归，即可知道总节点数。
* p.s. 为了计算快，这里使用了移位操作，`1<<m`的值就等于`2^m`。树的高度是`2^h-1`，即`(1<<h)-1`
* 时间复杂度: O(h^2), 其中`h = logN`; 空间复杂度: O(logN)


<![幻灯片1.JPG](https://pic.leetcode-cn.com/c626cb475a0bae30d060fde1e33db4b0eb57027c918966dcf8ff70d60342fb46-%E5%B9%BB%E7%81%AF%E7%89%871.JPG),![幻灯片2.JPG](https://pic.leetcode-cn.com/c4afb97f2d5d48ce58959781704072885b1b0818d5f037ce4958e477c4d51c47-%E5%B9%BB%E7%81%AF%E7%89%872.JPG),![幻灯片3.JPG](https://pic.leetcode-cn.com/fb96b312d853017e9fbda94a1b9d630902e95d2f1310adec085ec09bb5c29fc4-%E5%B9%BB%E7%81%AF%E7%89%873.JPG),![幻灯片4.JPG](https://pic.leetcode-cn.com/b85f2d3591f9ab27198a946ba068a7997198aa0063affa04506f8b54d514cfdc-%E5%B9%BB%E7%81%AF%E7%89%874.JPG),![幻灯片5.JPG](https://pic.leetcode-cn.com/e3b04a74a71ed5dc07dfffc7eb76f2546479aae9a4783a5d4a867ebc9ded4943-%E5%B9%BB%E7%81%AF%E7%89%875.JPG)>

```python []
class Solution:
    def countNodes(self, root: TreeNode) -> int:
        if root is None:
            return 0
        # step1: get h_left
        h_left = 0
        curr = root.left
        while(curr):
            h_left += 1
            curr = curr.left
        # step2: get h_right
        h_right = 0
        curr = root.right
        while(curr):
            h_right += 1
            curr = curr.left
        # step3: compare h_left and h_right
        if h_right == h_left: 
            return (1<<h_left) + self.countNodes(root.right)
        else:
            return self.countNodes(root.left) + (1<<(h_right))
```