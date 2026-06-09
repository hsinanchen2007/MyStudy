### 解题思路
![图片.png](https://pic.leetcode-cn.com/18b5dc60b50132059101023adf0f0f22280459a8166c5161953e6f318dbc0757-%E5%9B%BE%E7%89%87.png)

二叉搜索树的**中序遍历是有序的**,所以只要判断是否满足这个条件就行了。
一旦不满足，提前结束。

**我看有些也是用这个思路，不过他们用了栈保存数据，O(n)的空间复杂度。
其实没有必要全部保存，因为只要与上一个比较就行了。**

**时间复杂度O(n)，空间复杂度O(1)**

### 代码

```java
class Solution {
    public boolean isValidBST(TreeNode root) {
        if (root == null) return true;
        long[] current = {Long.MIN_VALUE};  // current value, default long min value
        int[] flag = new int[1];   // flag
        func(root, current, flag);
        return flag[0] == 0;
    }
    private void func(TreeNode root, long[] current, int[] flag){
        if (root == null || flag[0] == 1) return;  // root is null or not satisfy (fast fail)
        func(root.left, current, flag);
        if (current[0] >= root.val) flag[0] = 1;   // not satisfy
        current[0] = root.val;  // update current value
        func(root.right, current, flag);
    }
}
```