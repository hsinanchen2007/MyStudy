# 思路
本题中涉及到二叉树中距离的求解，那么首先可以回忆如何在二叉树中求两个节点的距离？
答案是找到两个节点的最近公共祖先，然后分别计算节点与最近公共祖先的高度差，并相加。

![image.png](https://pic.leetcode-cn.com/3b6209bffd1257e1f3555859d9403308aff1f9622f86361599d9ae3de7d81656-image.png)

考虑官方的图例，对于节点5与节点0，最近公共祖先为节点3（根节点）。
节点5到节点0的高度差为1，节点0到节点1的高度差为2，那么两个节点的距离为1+2=3。


那么为了获取所有节点到目标节点的距离，需要获取目标节点与所有节点的最近公共祖先。
首先考虑目标节点的祖先，**目标节点的祖先即从根节点到目标节点这一路径**。对于每个祖先，目标节点到其的距离为i，那么其他节点到当前祖先节点的距离（高度）应为K-i，由此便很容易计算出所有满足题意的节点。

```
class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, K: int) -> [int]:
        result = []
        path = []
        def find_path(root, dire, cur_path):
            if root:
                cur_path.append((root, dire))
                if root == target:
                    return True
                
                if find_path(root.left, 'l', cur_path) or \
                    find_path(root.right, 'r', cur_path):
                    return True

                cur_path.pop()
 
            return False
        
        def find_root_with_distance(root, dire, dis, goal, nodes):
            if root:
                if dis == goal:
                    nodes.append(root.val)
                if dis < goal:
                    """
                    关于方向的说明，此前已经求出了到达目标节点的路径与方向，观察题例
                    如果target=5， 那么对于祖先节点5（自身）来说，可能的节点存在于自身两个方向；
                    对于祖先节点3来说，目标节点在其左子树，那么左子树中可能的点已经由下层的节点计算，自身只需要计算右子树即可
                    """
                    # 关于方向的说明
                    if dire == 'l':
                        find_root_with_distance(root.right, 'a', dis+1, goal, nodes)
                    elif dire == 'r':
                        find_root_with_distance(root.left, 'a', dis+1, goal, nodes)
                    else:
                        find_root_with_distance(root.right, 'a', dis+1, goal, nodes)
                        find_root_with_distance(root.left, 'a', dis+1, goal, nodes)

        find_path(root, None, path)
        for i, (root, _) in enumerate(path):
            # 方向存储在下一个节点中
            dire = path[i+1][1] if i + 1 < len(path) else 'a'
            nodes = []
            dis = len(path) - i - 1
            goal_dis = K - dis
            find_root_with_distance(root, dire, 0, goal_dis, nodes)
            result.extend(nodes)
        
        return result
```


