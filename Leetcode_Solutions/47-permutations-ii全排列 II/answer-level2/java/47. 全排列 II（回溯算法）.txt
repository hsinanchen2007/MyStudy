### 解题思路
去重思路             
if(i != 0 && nums[i] == nums[i-1] && visited[i - 1] == false){
    continue;
}
看下图，什么时候continue？也就是for循环一次之后，下标i = 0 + 1 = 1,也就是第二个2时，此时2与前一个数相同，且前一个数没选（也就意味着这个2是新的一次排列），这时候应该剪枝
i != 0 主要是防止越界
![image.png](https://pic.leetcode-cn.com/8d3043ce1b5f3defb41a51d74461fc0e99604a522e2b68e2f100955cb5b6bc94-image.png)


### 代码

```java
class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
       List<List<Integer>> results = new ArrayList<>();
        if (nums == null){
            return results;
        }
        Arrays.sort(nums);
        dfs(nums, new boolean[nums.length], new ArrayList<Integer>(), results);
        return results;
    }
    
    private void dfs(int[] nums,
                    boolean[] visited,
                    List<Integer> permutation,
                    List<List<Integer>> results){
        if(nums.length == permutation.size()){
            results.add(new ArrayList<Integer>(permutation));
            return;
        }
        
        
        for (int i = 0; i < nums.length; i++){
            if(visited[i]){
                continue;
            }
            //前面的数还没加进去，后面的当然不能选  剪枝！！visited[i - 1] == true时会很慢
            if(i != 0 && nums[i] == nums[i-1] && visited[i - 1] == false){
                continue;
            }
            
            permutation.add(nums[i]);
            //标记已经使用过
            visited[i] = true;
            dfs(nums, visited, permutation, results);
            visited[i] = false;
            permutation.remove(permutation.size() - 1);
        }
    }

}
```