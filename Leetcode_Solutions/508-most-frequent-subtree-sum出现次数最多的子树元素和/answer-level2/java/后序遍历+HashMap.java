```java
class Solution {
    private Map<Integer, Integer> sumCount = new HashMap<>();
    private List<Integer> list = new ArrayList<>();
    public int[] findFrequentTreeSum(TreeNode root) {
        if (root == null) {
            return new int[0];
        }
        postOrder(root);
        int maxCount = 0;
        for (Map.Entry<Integer, Integer> entry : sumCount.entrySet()) {
            if (maxCount < entry.getValue()) {
                maxCount = entry.getValue();
                list.clear();
                list.add(entry.getKey());
            } else if (maxCount == entry.getValue()) {
                list.add(entry.getKey());
            }
        }
        int[] ans = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            ans[i] = list.get(i);
        }
        return ans;
    }

    private int postOrder(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int sum = root.val + postOrder(root.left) + postOrder(root.right);
        sumCount.put(sum, sumCount.getOrDefault(sum, 0) + 1);
        return sum;
    }
}
```
