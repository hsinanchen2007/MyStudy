除了需要判断子树是不是BST、还需要判断左子树的最大值是否小于当前节点的值，右子树的最小值是否大于当前节点的值。
递归函数的返回值如果作为判断这个子树是否是BST的话，就无法返回这个子树的范围了。因此，有两个解决方案：
- 在输入参数中增加一个引用（或者指针），用作额外的输出，以记录这个子树的值的范围；
- 使用了一个全局变量来记录刚刚处理的这个子树的数值范围。

对于Java，无法使用指针，如果要额外使用一个对象作为最大值和最小值的引用的话，又需要创建一个新的对象，感觉有点浪费。因此采用了第二个方案，即使用
注意：如果使用全局变量这种方式的话，就无法并行处理左子树与右子树了，实际使用中需要深思。


```Java []
class Solution{
    int min, max; //global variables

    public boolean isValidBST(TreeNode root) {
        if(root==null){ //test case #2 is []
            return true;
        }
        return checkBST(root);
    }

    private boolean checkBST(TreeNode node){
        int min, max;
        if(node.left!=null){
            if(checkBST(node.left)){
                //left subtree is a BST
                if(this.max<node.val){
                    //max value of left subtree < currentNode.val
                    min=this.min;
                }else{  
                    return false;
                }
            }else{
                return false;
            }
        }else{
            //no left subtree, min value of current tree is currentNode.val
            min=node.val;
        }
        if(node.right!=null){
            if(checkBST(node.right)){
                if(node.val<this.min){
                    max=this.max;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else{
            max=node.val;
        }
        this.min=min;
        this.max=max;
        return true;
    }
}
```
当然，如果使用引用的话，写起来应该也可以。下面的写法只是思路，没有实际调试：
```Java []
class Solution{

    public boolean isValidBST(TreeNode root) {
        if(root==null){ //test case #2 is []
            return true;
        }
        return checkBST(root， new int[2]);
    }

    //minmax contains 2 values. minmax[0] is min value of node, minmax[1] is max value of node
    private boolean checkBST(TreeNode node, int[] minmax){
        int min, max;
        if(node.left!=null){
            if(checkBST(node.left, minmax)){
                //left subtree is a BST
                if(minmax[1]<node.val){
                    //max value of left subtree < currentNode.val
                    min=minmax[0];
                }else{  
                    return false;
                }
            }else{
                return false;
            }
        }else{
            //no left subtree, min value of current tree is currentNode.val
            min=node.val;
        }
        if(node.right!=null){
            if(checkBST(node.right, minmax)){
                if(node.val<minmax[0]){
                    max=minmax[1];
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else{
            max=node.val;
        }
        minmax[0]=min;
        minmax[1]=max;
        return true;
    }
}
```