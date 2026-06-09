### 执行结果
![image.png](https://pic.leetcode-cn.com/99c40c90524224db0be00e50ac8fa7e19ce548d37371390e5ece96706a3588ed-image.png)
### 解题思路
将根节点root，List类型的res作为输入：

```
1. 首先判断root节点是否为空，如果为空直接返回空的res;
2. 若root不为空，先判断root.left是否为空，不为空时将root.left和res作为后序遍历函数的输入；
3. 再判断root.right是否为空，不为空时将root.right和res作为后序遍历函数的输入；
4. 将当前root节点的值添加到res中；
5. 返回res;**
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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
		return postOrder(root, res);
    }
    public static List<Integer> postOrder(TreeNode root,List<Integer> res){
		
		if(root==null) {
			return res;
		}else {
			if(root.left!=null) {
				postOrder(root.left, res);
			}
			if(root.right!=null) {
				postOrder(root.right, res);
			}
			res.add(root.val);
		}
		
		return res;
	}
}
```