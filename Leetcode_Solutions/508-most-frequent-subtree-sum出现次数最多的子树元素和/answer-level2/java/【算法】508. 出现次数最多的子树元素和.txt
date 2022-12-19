### 解题思路
简单的递归求和，分别求出左子树和右子树的和，然后再加上节点本身的值。求出sum后，用一个map保存全局的sum对应的出现频率。并且用一个maxFrequency保存最大频率。

求完所有节点的sum值后。遍历map将所有频率与maxFrequency的sum输出(这里使用的是stream的方式，会影响执行时间，可以用普通遍历的方式)。

时间复杂度：$O(lgn) + O(n) = O(n)$, 空间复杂度: $O(n)$

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

    private Map<Integer, Integer> frequencyMap = new HashMap();
    private int maxFrequency = 0;

    public int[] findFrequentTreeSum(TreeNode root) {
        getSum(root);

        return frequencyMap.entrySet().stream().filter(entry -> entry.getValue().equals( maxFrequency)).mapToInt(Map.Entry::getKey).toArray();
    }

    private int getSum(TreeNode root) {
        if(root == null){
            return 0;
        }
        int sum = root.val + getSum(root.left) + getSum(root.right);
        int frequency = frequencyMap.getOrDefault(sum, 0) + 1;
        frequencyMap.put(sum, frequency);
        maxFrequency = frequency > maxFrequency ? frequency : maxFrequency;
        return sum;
    }   
}
```