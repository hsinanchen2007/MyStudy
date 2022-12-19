### 解题思路
我写的应该比较简洁，参数少的原因是抓住了后序是``左--右--根``的特点，所以后序遍历从后向前是``根--右--左``，故在递归时根本没有必要将后序遍历的数组界限传入，每次有节点加入就自减一就行，只要满足了先拿到根节点然后遍历右子树，再遍历左子树这个原则就Okay。
至于递归如何写，其实把握三个原则就行：
* 递归出口，这里就不解释了
* 每次递归的返回值，这里很明显就是题目要求的root节点
* 单次递归需要做的事，我们需要构建一个树，那么单次递归就是拿到根节点，并且指向正确的左右子树即可。

### 代码

```java
class Solution {
    int index;
    Map<Integer,Integer> map = new HashMap<>();
    public TreeNode buildTree(int[] inorder,int[] postorder){
        index = inorder.length - 1;
        for(int i = 0;i <= index; i++){
            map.put(inorder[i],i);
        }
        return buildTreeByRecursion(inorder,postorder,0,index);
    }
    private TreeNode buildTreeByRecursion(int[] inorder,int[] postorder,int inorder_start,int inorder_end){
        if(inorder_start > inorder_end) return null;
        //先拿到根节点的值,确定其在中序遍历的位置，并且将其后序遍历的索引值的末尾往前一位
        int inorder_root = map.get(postorder[index]);
        TreeNode root = new TreeNode(postorder[index--]);
        //然后确定左右子树，并且递归即可
        // 注意哦！是必须先递归右子树，再递归左子树，因为后序是左右根的顺序，后序末尾自减一，此时应该是右子树的根节点！
        // 所以必须全部右子树构建完成再去构建左子树
        root.right = buildTreeByRecursion(inorder,postorder,inorder_root + 1,inorder_end);
        root.left =  buildTreeByRecursion(inorder,postorder,inorder_start,inorder_root - 1);
        return root;
    }
}
```