### 解题思路
参考：https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/solution/marveljian-dan-de-xue-xi-bi-ji-501-by-tyanyonecanc/

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