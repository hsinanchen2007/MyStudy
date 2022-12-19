# 用递归简单实现

*二叉搜索树的特点是*
1. 左边的子节点 必定小于根节点 
2. 右边的子节点必定大于根节点 那么寻找等于的子节点就是二分法，只是这次我们二分的对象是二叉树。

那么我们的步骤就是这样的。
 比较根节点和目标值的大小
 if(根节点 > 目标节点）就说明 目标节点在左树上
 else 就说明目标节点在右树上。


***用递归可以非常清楚而简单的实现这一过程***

```
 public TreeNode beautifulSearchBST(TreeNode root ,int val){
        //搜索命中
        if (root == null || root.val == val) return root;
        //三目运算符显得更加帅气
        return val < root.val ? searchBST(root.left,val):searchBST(root.right,val);
    }
```
为了能够更酷一点我用的是三目运算符写的，当然本质上就是if else。

 

```
 public TreeNode beautifulSearchBST(TreeNode root ,int val){
        //搜索命中
        if (root == null || root.val == val) return root;
        if(val < root.val>){
            return   searchBST(root.left,val);
        }else{
            searchBST(root.right,val);
        }
        return val < root.val ? searchBST(root.left,val):searchBST(root.right,val);
    }
```


