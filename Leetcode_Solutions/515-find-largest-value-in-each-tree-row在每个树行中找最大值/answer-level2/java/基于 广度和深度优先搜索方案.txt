### 解题思路
此题要计算每层最大值，比较适合 BFS 方案，DFS 的话需要一个额外存储O(1)操作。

1、广度优先搜索
2、深度优先搜索

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

    private Map<Integer, Integer> maxNums;

    private Queue<TreeNode> queue = new LinkedList<>();

    public List<Integer> largestValues(TreeNode root) {
        return evalLargestWithBFS(root);
    }


    // 广度搜索
    private List<Integer> evalLargestWithBFS(TreeNode node){
        List<Integer> result = new ArrayList<>(16);
        if (node == null) {
            return result;
        }
        queue.offer(node);
        int size, max;
        TreeNode temp;
        while(!queue.isEmpty()){
            size = queue.size();
            // 重置最小值
            max = Integer.MIN_VALUE;
            // 每次都处理当前深度的所有节点, size = 当前深度的节点数量
            for (int i = size ;i > 0 ;i --) {
                temp = queue.poll();
                max = Math.max(max, temp.val);
                if (temp.left != null) {
                    queue.offer(temp.left);
                }
                if (temp.right != null) {
                    queue.offer(temp.right);
                }
            }
            result.add(max);
        }
        return result;
    }

    // 深度搜索
    private List<Integer> evalLargestWithDFS(TreeNode node){
        maxNums = new HashMap<>(128);
        evalLargestWithDFS(node, 0);
        return toArrays();
    }

    // 递归计算
    private void evalLargestWithDFS(TreeNode node, int h){
        if (node == null){
            return;
        }
        Integer v = maxNums.get(h);
        if (v == null) {
            maxNums.put(h, node.val);
        }else {
            maxNums.put(h, Math.max(node.val, v));
        }
        if (node.left != null) {
            // 左侧
            evalLargestWithDFS(node.left, h + 1);
        }
        if (node.right != null) {
            // 右侧
            evalLargestWithDFS(node.right, h + 1);
        }
    }

    /**
    * 转换结果
    */
    private List<Integer> toArrays(){
      List<Integer> ll = new ArrayList<>(maxNums.size());
      maxNums.forEach((h, v) -> {
          ll.add(h, v);
      });
      return ll;
    }

}
```