### 解题思路
设置一个状态数组，记录已经添加进list中的元素（设置状态为1）
同时在递归后，重新设置状态为0，并从list中移除元素

### 代码

```java
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        int len = nums.length;
        dfs(nums,new int[len],len,new ArrayList<>(),res);
        return res;
    }

    private void dfs(int[] nums,int[] visited,int len,List<Integer> list,List<List<Integer>> res){
        if (list.size() == len){
            res.add(new ArrayList<>(list));
            return;
        }
        for(int i = 0;i < len;i++){
            if (visited[i] == 0){
                list.add(nums[i]);
                visited[i] = 1;
                dfs(nums,visited,len,list,res);
                visited[i] = 0;
                list.remove(new Integer(nums[i]));
            }
        }
    }
}
```