## 解题方案

### 思路

递归结束条件：
 - 都为空指针则返回 `true`
 - 只有一个为空则返回 `false`

递归过程：
 - 判断两个指针当前节点值是否相等
 - 判断 A 的右子树与 B 的左子树是否对称
 - 判断 A 的左子树与 B 的右子树是否对称

短路：

在递归判断过程中存在短路现象，也就是做 `与` 操作时，如果前面的值返回 `false` 则后面的不再进行计算

时间复杂度：$O(n)$

### 代码

```Java []
class Solution {
    public boolean isSymmetric(TreeNode root) {
        return isMirror(root, root);
    }

    public boolean isMirror(TreeNode t1, TreeNode t2) {
        if (t1 == null && t2 == null) return true;
        if (t1 == null || t2 == null) return false;
        return (t1.val == t2.val)
            && isMirror(t1.right, t2.left)
            && isMirror(t1.left, t2.right);
    }
}
```

### 画解


<![frame_00001.png](https://pic.leetcode-cn.com/f8516e645b7183696adfde874577fa2f80d8728e20b8641820b51a44b44318aa-frame_00001.png),![frame_00004.png](https://pic.leetcode-cn.com/6024712a2456426cd84e57d227ceaf8438e20b7f2f38bf661d0f69ec64c38a24-frame_00004.png),![frame_00007.png](https://pic.leetcode-cn.com/0e3279b3231524a8feea607f0e6633ece71591777a7ffc6b657eef45999b6b28-frame_00007.png),![frame_00010.png](https://pic.leetcode-cn.com/f37aba455af57908c68b9e623de09bcff4c77a4a16002a8136eac0277b703337-frame_00010.png),![frame_00013.png](https://pic.leetcode-cn.com/74642df3c54b5c63bde7172d1f5bf8d9584baa57d3547eba72961ceb97f29a04-frame_00013.png),![frame_00018.png](https://pic.leetcode-cn.com/abd2ee341d2b175d3c9fd08e615e83e6e50af118e166c99a6ddcbe068fa5b61d-frame_00018.png),![frame_00022.png](https://pic.leetcode-cn.com/89e308be5d9d87880f73412782483313ecf09aef2bb6c2d8c23a472672dc46cf-frame_00022.png),![frame_00026.png](https://pic.leetcode-cn.com/52c1f6c6b7ff3166c9e32697d22efb406ec2f09b2c2e278bd573452f15a08148-frame_00026.png)>
