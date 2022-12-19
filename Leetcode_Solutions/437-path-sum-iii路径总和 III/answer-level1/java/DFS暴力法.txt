# 首先能想到的最直接的是暴力法.
**注意题中描述，只能是当前位置向下，若root根节点有left和right节点，即使root.value+left.value+right.value==sum 也不满足要求。**
我们用一个linkedList<Integer> path来记录访问的位置，用count标识满足条件的结果数量。由于只能向下访问，每访问一个节点，path加入一个位置，对当前path从后往前进行计算，进行累加，看满足sum条件的有几个，对count进行相加。遍历完left记得从path中remove last，当遍历完整个节点即可确定有多少解。
```
 public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    private int target;
    private LinkedList<Integer> pathList = new LinkedList<>();

    // 记录结果和;
    private int resultCount = 0;

    public int pathSum(TreeNode root, int sum) {
        this.target = sum;
        dfs(root);
        return resultCount;
    }

    private void dfs(TreeNode node) {
        if (node == null) {
            pathList.addLast(0);
            return;
        }
        // 记录路径
        pathList.addLast(node.val);
        resultCount += getTargetCount(pathList);
        dfs(node.left);
        pathList.removeLast();
        dfs(node.right);
        pathList.removeLast();
    }

    private int getTargetCount(LinkedList<Integer> pathList) {
        int lens = pathList.size();
        if (lens == 0) {
            return 0;
        }
        int count = 0;
        int sum = 0;
        for (int i = lens - 1; i >= 0; i--) {
            sum += pathList.get(i);
            if (sum == target) {
                count++;
            }
        }
        return count;
    }
```
