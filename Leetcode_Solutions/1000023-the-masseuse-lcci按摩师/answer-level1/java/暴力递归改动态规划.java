### 解题思路
注释的地方是暴力递归的代码，
根据暴力递归的代码改成了dp,时间、空间复杂度都是O(n)。

### 代码

```java
import java.util.*;
class Solution {
    public int[] visited;
    public int[] dp1;
    public int massage(int[] nums) {
     // visited = new int[nums.length + 1];
     // Arrays.fill(visited, -1);
      //return dfs(nums,0);
      dp1 = new int[nums.length + 2];
      return dp(nums);

    }
    //递归
    public int dfs(int[] nums,int i){
        if(i>=nums.length){
            return 0;
        }
        if(visited[i] != -1) return visited[i];
        int res=Math.max(nums[i]+dfs(nums,i+2),dfs(nums,i+1));
        visited[i] = res;
        return res;
    }
    //以下递归改成动态规划
    public int dp(int[] nums){
        for(int i=nums.length-1;i>=0;i--){
            dp1[i]=Math.max(nums[i]+dp1[i+2],dp1[i+1]);      
        }
        return dp1[0];
    }

}
```