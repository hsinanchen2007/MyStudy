### 解题思路
利用深度优先构建目标容器
![面试题32-Ⅲ.从上到下打印二叉树.png](https://pic.leetcode-cn.com/c4b00463107f133c7462a9ed3a0f9110d3bf0ce7315169ea547a0fc6a06b37ef-%E9%9D%A2%E8%AF%95%E9%A2%9832-%E2%85%A2.%E4%BB%8E%E4%B8%8A%E5%88%B0%E4%B8%8B%E6%89%93%E5%8D%B0%E4%BA%8C%E5%8F%89%E6%A0%91.png)


### 代码

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

    int nowDepth;
    int maxDepth;
    LinkedList[] res;

    public List<List<Integer>> levelOrder(TreeNode root) {

        nowDepth = -1;
        maxDepth = -1;
        res = new LinkedList[1000];
        List<List<Integer>> trueRes = new LinkedList<>();

        helper(root);

        for(int i = 0; res[i] != null; i++) {
            trueRes.add(res[i]);
        }

        return trueRes;
    }

    private void helper(TreeNode node) {
        if(node == null) return;
        nowDepth++;

        if(nowDepth > maxDepth) {
            LinkedList<Integer> temp = new LinkedList<>();
            temp.add(node.val);
            res[nowDepth] = temp;
            maxDepth = nowDepth;
        }
        else if(nowDepth % 2 != 0) {
            res[nowDepth].addFirst(node.val);
        }
        else {
            res[nowDepth].addLast(node.val);
        }

        helper(node.left);
        helper(node.right);

        nowDepth--;
    }
}




```