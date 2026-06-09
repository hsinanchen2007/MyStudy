考虑每一个节点，小偷有两种选择，偷，或者不偷。

用res存储这两种情况下能偷到的最多的钱。res[0]表示不偷该节点能得到的最多的钱，res[1]表示偷了该节点能得到的最多的钱。

- 如果某个节点是NULL，那么显然，res=[0, 0]
- 如果节点不为空
    - 不偷此节点的话，其两个子节点偷不偷都可以，对于每个子节点，就看是偷能得到的钱多，还是不偷能拿到的钱多。
        - left表示其左子节点偷或者不偷能得到的最多的钱，right表示其右子节点。
        - 那么，res[0] = max(left[0], left[1]) + max(right[0], right[1])
    - 如果偷这个节点，其两个子节点都不能偷。
        - 用var表示这个节点所拥有的钱
        - 所以，res[1] = var + left[0] + left[1]
- 由上述的状态转移公式，每个节点的计算都要用到两个子节点的计算结果，所以要用递归来实现
- 最后，返回root得到的res中，最大的一个，即max(res[0], res[1])

代码如下：
```Python
class Solution:
    def rob(self, root: TreeNode) -> int:
        # 
        def robinteger(root):
            # 如果节点本身就是空的，那无论偷不偷，都拿不到钱
            res = [0, 0]
            if not root: return res
            # res[1]表示节点被偷能拿到的最多的钱
                # 节点被偷的话，其子节点不能被偷
            left = robinteger(root.left)
            right = robinteger(root.right)
            res[1] += root.val + left[0] + right[0]
            # res[0]表示不偷该节点能拿到的最多的钱
                # 不被偷的话，无论其子节点是否被偷都可以
            res[0] += max(left[0], left[1]) + max(right[0], right[1])
            return res
        res = robinteger(root)
        return max(res[0], res[1])
```


