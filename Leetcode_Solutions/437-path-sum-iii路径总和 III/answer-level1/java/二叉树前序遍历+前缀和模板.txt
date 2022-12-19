建议做此题目前先做「560. 和为K的子数组」，然后就豁然开朗，无非是数据结构从数组变成了二叉树。

数组的遍历方式是从开始到结构的线性遍历，但是二叉树的遍历方式是前序遍历。


![image.png](https://pic.leetcode-cn.com/1b33236a00587af9ff0f8f2aed7247da453fe2c28450a7f27f98464077d4c0d3-image.png)

```
private int pathSum = 0;

    /**
    *
    * 初始化的时候，需要加入 prefixSum[0] = 1，因为当prefixSum == target时，也要算出现了一次。如果没有初始化，就漏掉了
    * @param root
    * @param sum
    * @return
    */
    public int pathSum(TreeNode root, int sum) {
        if (root == null) return 0;

        // key是前缀和, value是大小为key的前缀和出现的次数
        Map<Integer, Integer> prefixSum2Count = new HashMap<>();
        prefixSum2Count.put(0, 1);
        preOrderAndBacktrack(root, 0, sum, prefixSum2Count);
        return pathSum;
    }

    private void preOrderAndBacktrack(TreeNode root, int prefixSum, int target, Map<Integer, Integer> prefixSum2Count) {
        if (root == null) return ;

        /*###################*/
        prefixSum += root.val;

        // 判断有没有和为target的路径
        Integer count = prefixSum2Count.getOrDefault(prefixSum - target, 0);
        if (count > 0) {
            this.pathSum += count;
        }

        prefixSum2Count.put(prefixSum, prefixSum2Count.getOrDefault(prefixSum, 0) + 1);
        /*###################*/

        preOrderAndBacktrack(root.left, prefixSum, target, prefixSum2Count);
        preOrderAndBacktrack(root.right, prefixSum, target, prefixSum2Count);

        // 回溯，撤销递归前做的决定
        prefixSum2Count.put(prefixSum, prefixSum2Count.getOrDefault(prefixSum, 0) - 1);
    }
```
