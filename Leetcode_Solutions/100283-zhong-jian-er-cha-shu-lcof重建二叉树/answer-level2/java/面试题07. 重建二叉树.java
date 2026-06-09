### 解题思路
递归
时间复杂度：每个节点都需要创建，O(n)
空间复杂度：存储整个二叉树占用O(n)的空间

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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder.length==0 || inorder.length==0){
            return null;
        }
        // 前序遍历是先根再左再右，下面的孩子节点也是这样迭代
        // 于是前序遍历结果的第一个值就是根节点
        int val=preorder[0];

        // 中序遍历是先左再根再右，同样地孩子接点也是如此
        // 于是中序遍历结果的根节点之前的都是左节点（包括其孩子节点），根节点之后的都是右节点（包括其孩子节点）
        // 遍历中序结果，分别找到左右孩子节点的个数
        int leftNum=0;
        for(int inorderVal:inorder){
            if(inorderVal==val){
                break;
            }
            leftNum++;
        }
        int rightNum=inorder.length-leftNum-1;

        // 从前序遍历结果中，切分出左右孩子节点的前序结果
        int[] leftPreorder=new int[leftNum];
        int[] rightPreorder=new int[rightNum];
        System.arraycopy(preorder,1,leftPreorder,0,leftNum);
        System.arraycopy(preorder,leftNum+1,rightPreorder,0,rightNum);
        // 从中序遍历结果中，切分出左右孩子节点的中序结果
        int[] leftInorder=new int[leftNum];
        int[] rightInorder=new int[rightNum];
        System.arraycopy(inorder,0,leftInorder,0,leftNum);
        System.arraycopy(inorder,leftNum+1,rightInorder,0,rightNum);

        TreeNode node=new TreeNode(val);
        node.left=buildTree(leftPreorder,leftInorder);
        node.right=buildTree(rightPreorder,rightInorder);
        return node;
    }
}
```

**参考官方题解之后，对上述实现做了两点优化**
1、每次递归时数组拷贝效率太低，直接利用原数组中相应的指针来确定子树的前序中序遍历结果的边界。
2、利用HashMap查询根节点在中序遍历结果中的位置，不需要每次遍历数组。
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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if(preorder==null||preorder.length==0){
            return null;
        }
        HashMap<Integer,Integer> inorderMap=new HashMap<Integer,Integer>();
        for(int i=0;i<inorder.length;i++){
            inorderMap.put(inorder[i],i);
        }
        return build(preorder,0,preorder.length-1,inorder,0,inorder.length-1,inorderMap);
    }

    /* startIndexPre 前序遍历结果_开始指针
     * endIndexPre 前序遍历结果_结束指针
     * startIndexIn 中序遍历结果_开始指针
     * endIndexIn 中序遍历结果_结束指针
     */
    private TreeNode build(int[] preorder,int startIndexPre,int endIndexPre,int[] inorder,int startIndexIn,int endIndexIn,HashMap<Integer,Integer> inorderMap){
        // 递归
        // 没有节点时，返回null
        if(startIndexPre>endIndexPre){
            return null;
        }
        // 找到根节点的值
        int rootVal=preorder[startIndexPre];
        TreeNode root=new TreeNode(rootVal);
        
        int rootIndex=inorderMap.get(rootVal);
        // 左子树节点个数
        int leftNodesCount=rootIndex-startIndexIn;
        // 右子树节点个数
        int rightNodesCount=endIndexIn-rootIndex;

        // 指定左子树的前序遍历结果和中序遍历结果，创建左子树
        root.left=build(preorder,startIndexPre+1,startIndexPre+leftNodesCount,inorder,startIndexIn,startIndexIn+leftNodesCount-1,inorderMap);
        // 指定右子树的前序遍历结果和中序遍历结果，创建右子树
        root.right=build(preorder,endIndexPre-rightNodesCount+1,endIndexPre,inorder,endIndexIn-rightNodesCount+1,endIndexIn,inorderMap);
        return root;
    }
}
```
优化结果：
![无标题2.png](https://pic.leetcode-cn.com/969d8fa48db7c9b55db0485ac6720f51ae4cee69d7de0e21a88caeca37aa2b70-%E6%97%A0%E6%A0%87%E9%A2%982.png)
