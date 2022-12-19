### 解题思路
先排序，遇见重复的过滤，按照顺序回溯即可

### 代码

```java
class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        //list
        List<List<Integer>>  list      =  new ArrayList<>();
        List<Integer>        listItem  =  new ArrayList<>(); 
        if (nums.length == 0) {
            list.add(listItem);
            return list;
        }

        //排序去重
        Arrays.sort(nums);
        
        //回溯+剪枝
        dfs(nums, list, listItem, 0);

        return list;
    }

    //编写模版代码
    private void dfs(int[] nums, List<List<Integer>>  list, List<Integer>  listItem, int start)
    {
        list.add(new ArrayList(listItem));

        if (listItem.size() >= nums.length) {
            return;
        }
        
        for (int i = start; i < nums.length; i++) {
            //剪枝
            if (i > start && nums[i] == nums[i-1]) {
                continue;
            }
            listItem.add(nums[i]);
            dfs(nums, list, listItem, i+1);
            //回溯
            listItem.remove(listItem.size()-1);
        }
    }
}
```