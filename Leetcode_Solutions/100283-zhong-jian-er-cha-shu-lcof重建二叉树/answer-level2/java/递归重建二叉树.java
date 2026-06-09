### 解题思路
![重建二叉树.png](https://pic.leetcode-cn.com/3d9b220d7bd6690c74d395d60097aa4d4b28100722e1fe07b6d02289d0c0b902-%E9%87%8D%E5%BB%BA%E4%BA%8C%E5%8F%89%E6%A0%91.png)
分析：
1. preorder长度一定等于inorder的长度；
2. 前序遍历的第一个值x一定是根节点的取值；
2. 再中序遍历中找到x，x将inorder一分为二，左边即为左子树，右边即为右子树；
3. 这样可以计算得到左子树的长度Lleft和右子树的长度Lright；
4. 这样可以得知preorder的x元素后Lleft个元素是左子树的前序遍历，最后Lright个元素是右子树的谦虚便利
**递归**
*明确函数意义：*
buildTree(int preLeft, int preRight, int inLeft, int inRight)
利用前序遍历的数组preorder[preLeft]...preorder[preRight]和中序遍历的数组inorder[inLeft]...inorder[inRight]构造二叉树
*明确递归体：*
preorder[preLeft]为根节点的位置，inorder对应的位置为index
则左子树长度为index - inLeft
则inorder中右子树的部分为inorder[index + 1]...inorder[inRight]
则inorder中左子树的部分为inorder[0]...inorder[index - 1]
则preorder中左子树的部分为preorder[preLeft + 1]...preorder[index - inLeft + preLeft]
则preorder中右子树的部分为preorder[index - inLeft + preLeft + 1]...preorder[preRight]
从而递归调用：
        node.left = buildTree(preLeft + 1, preLeft + index - inLeft, inLeft, index - 1);
        node.right = buildTree(preLeft + index - inLeft + 1, preRight, index + 1, inRight);
*递归终止条件：*
构造二叉树的序列为空
        if(preLeft > preRight || inLeft > inRight){
            return null;
        }
        可以这么想：preorder长度一定等于inorder的长度
        则：preRight - preLeft == inRight - inLeft
        则pre和in任意一个为空，则返回null
# Trick
1. 使用HashMap查找preorder的元素再inorder中对应元素的位置
2. 将preorder申请为全局变量，避免递归时重复拷贝
### 代码

```java
class Solution {
    public HashMap<Integer, Integer> map;
    private int[] pre;
    public TreeNode buildTree(int[] preorder, int[] inorder) {   
        map = new HashMap<Integer, Integer>();
        for(int i = 0; i < inorder.length; i++){
            map.put(inorder[i], i);
        }
        pre = preorder;

        int n = preorder.length;

        return buildTree(0, n -1, 0, n-1);  
    }

    public TreeNode buildTree(int preLeft, int preRight, int inLeft, int inRight){
        if(preLeft > preRight || inLeft > inRight){
            return null;
        }
        int rootVal = pre[preLeft];
        TreeNode node = new TreeNode(rootVal);
        int index = map.get(new Integer(rootVal));
        
        node.left = buildTree(preLeft + 1, preLeft + index - inLeft, inLeft, index - 1);
        node.right = buildTree(preLeft + index - inLeft + 1, preRight, index + 1, inRight);

        return node;
    }
}
```