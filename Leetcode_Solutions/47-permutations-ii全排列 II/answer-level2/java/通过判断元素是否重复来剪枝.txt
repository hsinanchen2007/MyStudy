
因为题目给的测试用例不一定为有序数列，所以此处不用一个变量存储当前深度的前一个值。
用一个集合 Set 存储当前深度已经用过的值，结合前一题 全排列I ,即可得出答案。

```java
class Solution {
    private List<List<Integer>> ans;
    public List<List<Integer>> permuteUnique(int[] nums) {
        ans = new ArrayList<>();
        boolean[] visited = new boolean[nums.length];
        List<Integer> list = new ArrayList<>(nums.length);

        dfs(nums,visited,list,0);

        return ans;
    }

    private void dfs(int[] nums,boolean[] visited,
    List<Integer> list,int depth){
        if(depth == nums.length){
            List<Integer> temp = new ArrayList<>();
            temp.addAll(list);
            ans.add(temp);
            return;
        }
        //通过集合判断
        Set<Integer> set = new HashSet<>();

        for(int i = 0;i < nums.length;i++){
            if(visited[i] || set.contains(nums[i])) continue;
            set.add(nums[i]);
            list.add(nums[i]);
            visited[i] = true;
            dfs(nums,visited,list,depth+1);
            //reset state
            list.remove(depth);
            visited[i] = false;
        }
    }
}
```
