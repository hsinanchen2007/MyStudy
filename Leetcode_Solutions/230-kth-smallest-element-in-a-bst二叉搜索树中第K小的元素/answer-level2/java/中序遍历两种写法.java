**二叉搜索树的中序遍历就是从小到大的排序，所以只需要进行中序遍历，在中序遍历的过程中进行判断就可以时间复杂度为O（n）**
非递归解法，使用栈来解决，代码如下：
空间复杂度为：O（n）
```
class Solution {
     public int kthSmallest(TreeNode root, int k) {
        return middleOrder(root,k,0);
    }
    public int  middleOrder(TreeNode root,int k,int count){
        Stack<TreeNode> s = new Stack<>();
        int res = 0;
        while(root!=null || !s.isEmpty()){ //循环条件需要注意
            //把左边节点加入到栈中
            while(root!=null){
                s.push(root);
                root = root.left;
            }
            root = s.pop();
            if(++count == k){
                res = root.val;
                return res;
            }
            root = root.right;//以便把右边的节点加入到栈中
        }
        return res;
    }
}

```
递归解法,空间复杂度为O（lgn）
```
class Solution {
    int res = 0,count = 0;
    public int kthSmallest(TreeNode root, int k) {
        middleOrder(root,k);
        return res;
    }
    
    public void middleOrder(TreeNode root,int k){
        if(root == null) return;
        middleOrder(root.left,k);
        if(++count == k){
            res = root.val;
            return;
        }
        middleOrder(root.right,k);
    }
}

```

