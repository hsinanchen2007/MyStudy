### 解题思路
先说说我们筛选的思路
假设数组中的元素是 abbcd，我们使用一个变量来保存每一次所添加的节点，这个初始值我设置的是Integer.MIN_VALUE，要避免和测试用例中的数据出现相同，当然如果这个题的测试用例中包含Integer.MIN_VALUE这个数据，我可能就得换个别的方法设置。

我们每次往list中添加一个数值时，就用last来保存，那么当递归回溯时，我们要在当前层换一个点加入List。
假设当前层是ab，回溯时b退栈，last此时记录的就是b，那么添加的时候就会在第二层避开重复的b，从而选择c入栈，就保证了数据的唯一。这一切的前提就是数据得有序，确保重复的数据是挨着的。

### 代码

```java
class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        dfs(nums, new ArrayList<>(), res,new int[nums.length]);
        return res;
    }

    private void dfs(int[] nums, List<Integer> temp, List<List<Integer>> res,int[] visited){
        if (temp.size() == nums.length){
            res.add(new ArrayList<>(temp));
            return;
        }
        int last = Integer.MIN_VALUE;
        for(int i = 0;i < nums.length;i++){
            if (visited[i] == 0 && nums[i] != last){
                visited[i] = 1;
                temp.add(nums[i]);
                last = nums[i];
                dfs(nums, temp, res, visited);
                temp.remove(temp.size()-1);
                visited[i] = 0;
            }
        }
    }
}
```