### 解题思路
深度递归遍历，搜索该树的子树元素和，然后用map记录下来，同时记录下出现的最大次数max
遍历map，取出value为max的所有key即可。
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
    public int[] findFrequentTreeSum(TreeNode root) {
        Map<Integer,Integer> map = new HashMap<>();
        //计算以root为根的子树元素和，并存储进map中
        int[] num = new int[1];
        dfs(root,map,num);
        Set<Integer> integers = map.keySet();
        List<Integer> res = new ArrayList<>();
        for (Integer integer : integers) {
            if (map.get(integer) == num[0])
                res.add(integer);
        }
        int[] result = new int[res.size()];
        for (int i = 0; i < res.size(); i++) {
            result[i] = res.get(i);
        }
        return result;
    }

    private int dfs(TreeNode root,Map<Integer,Integer> map,int[] num){
        if (root == null)
            return 0;
        int left = dfs(root.left,map,num);
        int right = dfs(root.right,map,num);
        int sum = root.val + left + right;
        if (map.containsKey(sum))
            map.put(sum,map.get(sum)+1);
        else 
            map.put(sum,1);
        if (map.get(sum) >=num[0])
            num[0] = map.get(sum);
        return sum;
    }
}
```