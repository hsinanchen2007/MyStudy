### 解题思路
要想判断整条路径上的总和是否与目标值相符，有两种做法。


### 解法一：
第一种方法：从根节点开始，每当遇到一个节点的时候，从目标值里扣除节点值，一直到叶子节点判断目标值是不是被扣完。

```Java []
 public boolean hasPathSum(TreeNode root, int sum) {
      return  helper(root,0,sum);
    }
    public boolean helper(TreeNode root,int cur,int sum)
    {
      if(root==null)
          return false;
        cur=cur+root.val;
        if(root.left==null&&root.right==null)
        {
            return cur==sum;
        }else
        {
            return helper(root.left,cur,sum)|| helper(root.right,cur,sum);
        }
    }

```
### 解法二：

第二种方法是，声明一个变量记录已经经过的节点的值之和，每经过一个节点就加上这个节点的值，在叶子节点判断变量值是否为目标值。

```Java []
  public boolean hasPathSum(TreeNode root, int sum) {
        if(root==null)
            return false;
        if(root.left==null&&root.right==null)
        {
            return sum-root.val==0;
        } 
        return hasPathSum(root.left,sum-root.val)||hasPathSum(root.right,sum-root.val);
    }
```

其实，做为树的递归题目是非常有套路可循的，因为树有两个分支，所以在递归里也有两个分支，一般是通过 递归 A（||，&&）递归 B 来实现分支的。只要明白了这一点，递归函数就不会很难设计。