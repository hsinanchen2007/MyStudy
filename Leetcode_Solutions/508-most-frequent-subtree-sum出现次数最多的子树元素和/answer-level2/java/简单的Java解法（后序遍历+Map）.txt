代码比较简单，直接上Java代码。

这是我的[LeetCode分类题解](https://github.com/caipengbo/LeetCode)（每日更新, issue内有总结），和我一起每日刷题吧！

```Java
    public int[] findFrequentTreeSum(TreeNode root) {
        TreeMap<Integer, Integer> map = new TreeMap<>();
        subTreeSum(root, map);
        // 获得最大次数
        int maxCount = 0;
        for (Integer key : map.keySet()) {
            maxCount = Math.max(maxCount, map.get(key));
        }
        ArrayList<Integer> ret = new ArrayList<>();
        for (Integer key : map.keySet()) {
            if (map.get(key) == maxCount) ret.add(key);
        }
        int[] arr = new int[ret.size()];
        for (int i = 0; i < ret.size(); i++) {
            arr[i] = ret.get(i);
        }
        return arr;
    }
    
    private int subTreeSum(TreeNode root, TreeMap<Integer, Integer> map) {
        if (root == null) return 0;
        int left = subTreeSum(root.left, map);
        int right = subTreeSum(root.right, map);
        int sum = left+right+root.val;
        map.put(sum, map.getOrDefault(sum, 0)+1);
        return sum;
    }
```