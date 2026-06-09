
![image.png](https://pic.leetcode-cn.com/ad804bbe4704f85d371ac759bd4eba1d476fa0227680c25c64a9901cfdf04d4d-image.png)

# 思路
1. 遍历每个节点。 关键点：递归
2. 计算以当前节点为路径终点的所有路径和。 关键点：用一个数组保存从根节点到当前节点路径

# 代码
```
    public int pathSum(TreeNode root, int sum) {
        return pathSum(root, sum, new int[1000], 0);
    }

    public int pathSum(TreeNode root, int sum, int[] array/*保存路径*/, int p/*指向路径终点*/) {
        if (root == null) {
            return 0;
        }
        int tmp = root.val;
        int n = root.val == sum ? 1 : 0;
        for (int i = p - 1; i >= 0; i--) {
            tmp += array[i];
            if (tmp == sum) {
                n++;
            }
        }
        array[p] = root.val;
        int n1 = pathSum(root.left, sum, array, p + 1);
        int n2 = pathSum(root.right, sum, array, p + 1);
        return n + n1 + n2;
    }
```

# 复杂度
遍历n个节点，为每个节点计算以当前节点为路径终点的所有路径和，平均路径长度是logn，所以平均时间复杂度是O(nlogn)

