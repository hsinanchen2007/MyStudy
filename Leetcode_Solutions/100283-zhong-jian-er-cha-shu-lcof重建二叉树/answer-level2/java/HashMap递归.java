### 解题思路
此处撰写解题思路

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
    //中序遍历map
    HashMap<Integer,Integer> inMap = new HashMap<>();
    //全局变量 前序遍历数组
    int[] copyOfPre;
    public TreeNode buildTree(int[] preOrder,int[] inOrder){
        copyOfPre = preOrder;
        for(int i = 0;i < inOrder.length;i++){
            //存放  数值  以及中序索引
            inMap.put(inOrder[i],i);
        }
        //进行递归 前序遍历根节点位置  中序遍历 左、右起始位置
        return dfs(0,0,inOrder.length - 1);
    }
    public TreeNode dfs(int preRoot,int inLeft,int inRight){
        if(inLeft > inRight) return null;
        TreeNode root = new TreeNode(copyOfPre[preRoot]);
        //获取中序遍历当前根节点的下标索引
        int index = inMap.get(copyOfPre[preRoot]);
        //前序左边根节点的起始位置  中序的起始位置  中序的终止位置
        root.left = dfs(preRoot + 1,inLeft,index - 1);
        //前序右边根节点的起始位置  中序的起始位置  中序的终止位置
        root.right = dfs(preRoot + index - inLeft + 1,index + 1,inRight);
        return root;
    }
}
```