### 解题思路
查找一组（无序的）数中的众数，无非就是遍历数组，统计每个数字的出现频率。那么二叉搜索树可以提供什么信息呢？
二叉搜索树的左右子结点和父结点之间有大小关系的限制，且二叉树的中序遍历是升序的。由此，问题可以转变成在一组升序排列的数中查找众数。

既然数字是升序的，就可以遍历一次完成统计。
借助三个变量，一个记录当前数字，一个记录当前数字的频率，一个记录上一个添加到List的数字的频率。

每访问一个数字，就将这个数字的出现次数加一，如果当前出现次数等于上一个添加到List的数字的出现次数，则在结果List中添加这个数字；
如果当前出现次数大于上一个添加到List的数字的出现次数，则清空结果List再添加这个数字，并把上一个添加到List数字的出现次数更新为当前出现次数。

还需注意两点：
若是首次访问，需要将上一个添加到List的数字的频率设为1；
每遇到一个新数字，则将当前数字的出现次数清零。


### 代码

```java
class Solution {
    private List<Integer> modes;
    private int cur;
    private int curTimes;
    private int lastTimes;
    public int[] findMode(TreeNode root) {
        modes = new LinkedList<>();
        inOrder(root);
        int[] res = new int[modes.size()];
        for(int i = 0; i < modes.size(); i++)
            res[i] = modes.get(i);
        return res;
    }
    private void inOrder(TreeNode root) {
        if(root == null)    return;
        inOrder(root.left);
        if(lastTimes == 0)
            lastTimes = 1;
        if(root.val != cur)
            curTimes = 0;
        cur = root.val;
        curTimes++;
        if(curTimes == lastTimes)   
            modes.add(cur);
        if(curTimes > lastTimes)
        {
            lastTimes = curTimes;
            modes.clear();
            modes.add(cur);
        }
        inOrder(root.right);
    }
}
```