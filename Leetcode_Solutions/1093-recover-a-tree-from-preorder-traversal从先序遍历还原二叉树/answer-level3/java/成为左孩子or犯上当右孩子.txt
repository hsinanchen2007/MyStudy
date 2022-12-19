### 解题思路

- 读出root的数值，建树。**读数字全部用位运算加速**
- 接下来的字符串就是规规矩矩的一串'-'和一个数字拼接而成，即k个'-'和一个数字num
- 用一个栈来存放"下一个上树结点到root的路径"，新上树的结点只有两种可能：
- (1) **成为上一个上树节点的左孩子**
- (2) **成为上一个上树节点的某一个祖先的右孩子**
- 当k小于上一个节点的深度时，说明要另起炉灶了，选(2)
- 否则，选(1)

#### 位运算加速

- 这里需要加速的是`num = num * 10;`
- `a * 10 = a * 2 * 5 = (a << 1) * 5`，记`b = (a << 1)`
- `b * 5 = b * 4 + b = (b << 2) + b`
- 所以`num = num * 10`可以写成

```java
num <<= 1;
num += num << 2;
```

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode recoverFromPreorder(String S) {
        // 前序遍历中，从左侧换到右侧后，原来左侧的子树都不会再出现
        // 根据这一点，可以使用一个栈来维护当前节点到root的路径
        TreeNode[] s = new TreeNode[1000];
        // 手动维护栈顶
        int curTopIndex = -1;

        int len = S.length();
        int index = 0; 

        // 搞定根节点
        int rootNum = 0;
        while (index < len && S.charAt(index) != '-') {
            rootNum <<= 1;
            rootNum += rootNum << 2;
            rootNum += S.charAt(index) - '0';
            ++index;
        }
        TreeNode root = new TreeNode(rootNum);
        ++curTopIndex;
        s[curTopIndex] = root;

        while (index < len) {
            // 读'-'
            int curDepth = index;
            while (index < len && S.charAt(index) == '-') {
                ++index;
            }
            curDepth = index - curDepth;

            // 读数字
            int num = 0;
            while (index < len && S.charAt(index) != '-') {
                num <<= 1;
                num += num << 2;
                num += S.charAt(index) - '0';
                ++index;
            }
           
            while (curTopIndex >= curDepth) {
                // 切换到某右子树了，丢弃左子树的信息
                --curTopIndex;
            }

            // 至此，可以直接上树和入栈了
            TreeNode newNode = new TreeNode(num);
            TreeNode t = s[curTopIndex];
            if (null != t.left) {
                t.right = newNode;
            } else {
                t.left = newNode;
            }

            ++curTopIndex;
            s[curTopIndex] = newNode;
        }

        return root;
    }
}
```