**思路1：** 递归，前序遍历对比是否为相同的树，详情如下。
```
public bool IsSameTree(TreeNode p, TreeNode q)
        {
            //递归终止情况1：p, q都是null
            if (p == null && q == null)
            {
                return true;
            }
            //递归终止情况2：p, q中有一个为空，或者是p, q的节点值不等
            else if (p == null || q == null || p.val != q.val)
            {
                return false;
            }
            else
            {
                //递归看左子树是否相同
                bool isLeftSameTree = IsSameTree(p.left, q.left);
                //递归看右子树是否相同
                bool isRightSameTree = IsSameTree(p.right, q.right);
                return isLeftSameTree && isRightSameTree;
            }
        }
```
