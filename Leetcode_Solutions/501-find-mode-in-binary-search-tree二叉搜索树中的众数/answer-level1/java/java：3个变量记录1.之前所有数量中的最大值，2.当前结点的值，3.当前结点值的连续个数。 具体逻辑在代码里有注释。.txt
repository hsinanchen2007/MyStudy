![image.png](https://pic.leetcode-cn.com/511c1a6765f73645698e40b55b380b54feb278898b2743c92714b7f1ee753e40-image.png)
```
class Solution {
    public List<Integer> maxValue;  // 用于将相同数量的众数保存
    public int curValue;  // 记录当前结点的值
    public int curCount = 0;  // 记录当前结点这个值的连续数量
    public int preMax;  // 记录之前遍历中数量的最大值
    public int[] findMode(TreeNode root) {
        maxValue = new ArrayList<>();
        inOrder(root);
        // 将结果转化为数组返回
        int[] res = new int[maxValue.size()];
        for(int i = 0; i < maxValue.size(); i++) {
            res[i] = maxValue.get(i);
        }
        return res;

    }

    public void inOrder(TreeNode root) {
        if(root == null) return;
        // 遍历左子树
        inOrder(root.left);
        // 当两值不相等时，当前值变换，以及当前的计数器归零
        if(curValue != root.val) {
            curValue = root.val;
            curCount = 0;
        }
        // 当前计数器加一
        curCount++;
        // 若当前计数器和之前保留的最大数量值相等，则将元素值加入List中
        if(curCount == preMax) {
            maxValue.add(root.val);
        }
        // 若当前计数器比之前保留的最大数量大，则将之前最大值更新
        // 将List清空
        // 将新元素加入
        if(curCount > preMax) {
            preMax = curCount;
            maxValue.clear();
            maxValue.add(root.val);
        }
        // 遍历右子树
        inOrder(root.right);
    }
}
```

