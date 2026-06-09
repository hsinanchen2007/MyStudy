**思路1：** 递归，通常来说一个问题可以分为多个子问题去解决&&问题和求解过程和子问题的求解过程一致&&存在递归终止条件，满足这三个条件就适合用递归。直接看题目例子的话比较容易发现，镜像对称就是二叉树每层是中心对称的。所以可以从顶层递归看每层是否是这样的中心对称。
```
public class SymmetricTree_101
    {
        public bool IsSymmetric(TreeNode root)
        {
            //检查每层是否对称
            return IsMirror(root, root);
        }

        private bool IsMirror(TreeNode root1, TreeNode root2)
        {
            //终止情况1：节点1为空，节点1的对称节点也为空
            if (root1 == null && root2 == null)
            {
                return true;
            }
            //终止情况2：节点1或节点2为空又或者节点1和节点2值不相等
            else if (root1 == null || root2 == null || root1.val != root2.val)
            {
                return false;
            }
            else 
            {
                //递归看下一层，是否是镜像对称的
                return IsMirror(root1.left, root2.right) && IsMirror(root1.right, root2.left);
            }
        }
    }
```
**注：** 不要太多自己去模拟递归的过程，会懵。可以直接假设递归方法完成了该过程。比如`IsMirror(root1.left, root2.right) && IsMirror(root1.right, root2.left);`可以直接假设该行完成了下一层是否镜像对称的判断，而不是过多地在脑子里模拟一层层递归的过程。