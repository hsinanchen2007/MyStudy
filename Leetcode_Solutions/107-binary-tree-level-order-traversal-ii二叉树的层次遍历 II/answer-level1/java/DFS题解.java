### 解题思路
采用DFS的方式，将从最左边的叶子节点开始返回，所以采用一个`depthNum`以及一个`map`来记录数值状态。每进入下一层叶子结点，`depthNum`将会加一，每层结点进行数据添加时，将会判断`map`中是否含有该层的数据数组。不存在则进行新增。存在则在原数据数组进行数据增加。

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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        int depthNum = 0;
        if (root != null) {
            List<Integer> arr = new ArrayList<>();
            arr.add(Integer.valueOf(root.val));
            map.put(depthNum, arr);
            depthSearch(root.left, root.right, depthNum, map);
        }

        List<List<Integer>> result = new ArrayList<>();
        for (int i=map.size() - 1; i>=0; --i) {
            result.add(map.get(i));
        }

        return result;
    }

    public void depthSearch(TreeNode left, TreeNode right, int depthNum, Map<Integer, List<Integer>> map) {
        depthNum++;
        if (left != null) {
            if (map.get(depthNum) != null) {
                List<Integer> arr = map.get(depthNum);
                arr.add(Integer.valueOf(left.val));
                depthSearch(left.left, left.right, depthNum, map);
            } else {
                List<Integer> arr = new ArrayList<>();
                arr.add(Integer.valueOf(left.val));
                map.put(depthNum, arr);
                depthSearch(left.left, left.right, depthNum, map);
            }
            
        }

        if (right != null) {
            if (map.get(depthNum) != null) {
                List<Integer> arr = map.get(depthNum);
                arr.add(Integer.valueOf(right.val));
                depthSearch(right.left, right.right, depthNum, map);
            } else {
                List<Integer> arr = new ArrayList<>();
                arr.add(Integer.valueOf(right.val));
                map.put(depthNum, arr);
                depthSearch(right.left, right.right, depthNum, map);
            }
            
        }
    }
}
```