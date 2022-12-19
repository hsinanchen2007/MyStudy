### 解题思路
代码简单

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

    ArrayList<Integer> res;
    HashMap<Integer, Integer> map;
    int maxCount;

    public int[] findFrequentTreeSum(TreeNode root) {

        maxCount = 0;
        res = new ArrayList();
        map = new HashMap();
        helper(root);

        int length = res.size();
        int[] arr = new int[length];

        for(int i = 0; i < length; i++) {
            arr[i] = res.remove(0);
        }

        return arr;
    }

    private int helper(TreeNode root) {
        if(root == null) return 0;

        int val = helper(root.left) + helper(root.right) + root.val;

        if(map.containsKey(val)) {
            int temp = map.get(val) + 1;
            if(temp > maxCount) {
                maxCount = temp;
                res.clear();
                res.add(val);
            }
            if(temp == maxCount && (res.contains(val) == false)) {
                res.add(val);
            }
            map.put(val, temp);
        }
        else if(maxCount <= 1) {
            maxCount = 1;
            res.add(val);
            map.put(val,1);
        }
        else {
            map.put(val,1);
        }

        return val;
    }
}
```