### 执行结果
执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :34.7 MB, 在所有 Java 提交中击败了47.14%的用户

### 解题思路
1. > 判断根节点是否为空，若为空直接返回结果res,否则将root的值保存在res中；
2. > 判断根节点的左子节点是否为空，不为空的化执行左子节点的前序遍历；
3. > 判断根节点的右子节点是否为空，不为空的化执行右子节点的前序遍历；
4. > 返回结果res;

*注意：因为用的递归方法，所以需要对每一轮的结果值进行传递，解决方法是将res作为遍历函数的输入。*


### 代码

```java

class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
       List<Integer> res = new ArrayList<Integer>();
	    return preOrder(root, res); 
    }
    public static List<Integer> preOrder(TreeNode root,List<Integer> res) {
        if(root==null) {
			return res;
		}else {
			res.add(root.val);
		}
		if(root.left!=null) {
			preOrder(root.left, res);
		}
		if(root.right!=null) {
			preOrder(root.right, res);
		}
		return res;
	}
}
```