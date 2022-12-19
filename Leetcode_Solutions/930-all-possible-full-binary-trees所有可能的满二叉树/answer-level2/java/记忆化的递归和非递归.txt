### 解题思路
此题的满二叉树，是所有节点只有0个或2个孩子。那么只有当N是奇数的时候，才可以求解，偶数肯定会存在只有1个孩子的节点。

满二叉树的构造：如果你要为某节点分配一个左节点，那么一定也要为它分配一个右节点。

为了列出所有满二叉树的排列，我们可以为左子树分配 x 节点，为右子树分配 N-1-x （其中减 1 减去的是根节点）节点，然后类推构造左右子树。

x = 1的时候，直接返回新的node即可，x>1时，求x的结果集，其x-2问题（以及之前更小的问题）肯定是已经处理过的，只需要之前的结果集合并起来，就是新的结果集，然后存入缓存中。x往后每次递增2

### 递归解法

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<TreeNode> allPossibleFBT(int N) {
        List<TreeNode> result = new ArrayList<>();
        if((N & 1) == 0){
            // N为偶数，无法构成满二叉树
            return new ArrayList<>();
        }
        // 缓存，避免重复计算，因为左右对称，只需要求一半就行了
        Map<Integer,List<TreeNode>> cache = new HashMap<>();
        List<TreeNode> res = getAllFBT(N,cache);
        return res;
    }

    private List<TreeNode> getAllFBT(int N,Map<Integer,List<TreeNode>> cache){
        List<TreeNode> res = new ArrayList<>();
        if (N == 1){
            TreeNode node = new TreeNode(0);
            res.add(node);
            return res;
        }
        for (int i = 1; i < N ;i = i+2) {
            int rightN = N - 1 - i;
            List<TreeNode> leftRes = cache.get(i);
            if (leftRes == null){
                // 计算得出，计入缓存中
                leftRes = getAllFBT(i,cache);
                cache.put(i,leftRes);
            }
            List<TreeNode> rightRes = cache.get(rightN);
            if (rightRes == null){
                // 计算得出，计入缓存中
                rightRes = getAllFBT(rightN,cache);
                cache.put(rightN,rightRes);
            }
            for (TreeNode left : leftRes){
                for (TreeNode right : rightRes){
                    TreeNode node = new TreeNode(0);
                    node.left = left;
                    node.right = right;
                    res.add(node);
                }
            }
        }
        return res;
    }
}
```


### 非递归解法

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<TreeNode> allPossibleFBT(int N) {
        Map<Integer, List<TreeNode>> cache = new HashMap<>();
        List<TreeNode> res = new ArrayList<>();
        if (N % 2 == 0) {
            return res;
        }
        TreeNode root = new TreeNode(0);
        res.add(root);
        cache.put(1, res);// 1的结果集
        // 偶数无法构成满二叉树，所以每次都+2
        for(int i=3; i<=N; i+=2){
            // 树的root求解
            res = new ArrayList<>();
            // 一侧子树数量从少到多加入结果集
            for(int j=1; j<=i-2; j+=2){
                // 每个 left 左子树， 对应 cache.get(i-j-1) 个右子树，一共有cache.get(j)个左子树
                for(TreeNode left : cache.get(j)){// 左侧树节点列表
                    for(TreeNode right: cache.get(i-j-1)){// 对应的右侧树的集合
                        TreeNode node = new TreeNode(0);
                        node.left = left;
                        node.right = right;
                        res.add(node);
                    }
                }
            }
            cache.put(i, res);
        }
        return cache.get(N);
    }
}
```