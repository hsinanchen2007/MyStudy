### 解题思路
最开始自己是构造二叉树这样子dfs的，后来才明白数组也可以dfs。dfs的核心是递归。

### 代码

```java
/*
 * Copyright (c) 2020
 * Author: xiaoweixiang
 */

public class Solution {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = new int[]{1, 1, 1, 1, 1};
        int s = 3;
        int result = solution.findTargetSumWays(nums, s);
        System.out.println("result = " + result);

    }


    int res = 0;

    public int findTargetSumWays(int[] nums, int S) {
        // 每个数字代表第几层的数，+ - 代表节点。然后dfs二叉树，然后记录最后的值是目标值的数量。
        // 首先构造二叉树
//        Node root = bulidTree(nums, S);
        // sumDfs(root,0,S);
        // 终于明白dfs不一定要用树，dfs是递归。
        dfs(0,nums,0,S);
        return res;
    }


    private void dfs(int index, int[] nums, int sum, int s) {
        if (index == nums.length) {
            if (sum == s) {
                res++;
            }
            return;
        }
        dfs(index+1,nums,sum+nums[index],s);
        dfs(index+1,nums,sum-nums[index],s);

    }

    private void sumDfs(Node root, int sum, int s) {
        if (root == null) {
            return;
        }
        sum += root.val;
        if (root.left == null && root.right == null) {
            if (sum == s) {
                res++;
            }
            return;
        }
        sumDfs(root.left, sum, s);
        sumDfs(root.right, sum, s);
    }


    private Node bulidTree(int[] nums, int s) {
        Node root = new Node(0);
        dfs(root, 0, nums, 0, s);
        return root;
    }

    private void dfs(Node root, int index, int[] nums, int sum, int s) {
        if (index == nums.length) {
            if (sum == s) {
                res++;
            }


            return;
        }
        int n = nums[index];
        root.left = new Node(-n);
        root.right = new Node(n);
        dfs(root.left, index + 1, nums, sum + root.left.val, s);
        dfs(root.right, index + 1, nums, sum + root.right.val, s);
    }

    class Node {
        int val = 0;
        Node left;
        Node right;

        public Node(int val) {
            this.val = val;
        }
    }

}
```