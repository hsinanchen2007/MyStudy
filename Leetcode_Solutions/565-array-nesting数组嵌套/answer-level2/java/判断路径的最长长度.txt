从数组给的关系可知其实就是求从子节点到父节点的最长路径。
使用一个boolean数组判断是否已经访问过该节点，遍历nums数组，如果num已经访问过，就说明已经在某一条路径上计算过，side为路径的长度，更新side的长度为最长即为答案。
```
class Solution {
    public int arrayNesting(int[] nums) {
        boolean[] visited = new boolean[nums.length];
        int res = 0;
        for(int i = 0;i < nums.length;i++){
            int num = i;
            int side = 0;
            while(!visited[num]){
                visited[num] = true;
                num = nums[num];
                side++;
            }
            res = Math.max(res,side);
        }
        return res;
    }
}
```
![565.png](https://pic.leetcode-cn.com/9f6bcf09faaf1262e0e6fb3c5f52e9307003e3894c12fdbefe4202a54a59f722-565.png)


