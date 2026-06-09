该问题可以分解为二叉树路径问题和数组中找到和为固定值的子数组问题。
对于二叉树路径问题，典型做法是使用dfs将所有路径收集起来。对于该方法的优化是使用回溯法，如此便不用把所有路径都收集，
只收集当前路径即可。
对于找到和为固定值的子数组问题。我们一般使用前缀和结构，遍历过程中将从头到该位置之和存入map，之后查找只需要
get(sum - target)即可找到以当前点结尾是否存在和为target的子数组。
本题中由于需要找到有多少条路径，因此map的值为当前sum出现的次数。
```
class Solution {
    private Map<Integer,Integer> map = new HashMap<>();
    private int target = 0;
    private int num = 0;
    public int pathSum(TreeNode root, int sum) {
        target = sum;
        map.put(0, 1);
        process(root, 0);
        return num;
    }
    public void process(TreeNode root, int curSum){
        if(root == null){
            return;
        }
        curSum += root.val;
        if(map.containsKey(curSum - target)){
            num += map.get(curSum - target);
        }
        if(map.containsKey(curSum)){
            map.put(curSum, map.get(curSum) + 1);
        }else{
            map.put(curSum, 1);
        }
        process(root.left, curSum);
        process(root.right, curSum);
        if(map.get(curSum) == 1){
            map.remove(curSum);
        }else{
            map.put(curSum, map.get(curSum) - 1);
        }
    }
}
```
