### 解题思路
此处撰写解题思路
虽然不是最高校的不过应该是最好理解的把；利用Set<List<Integer>>去重复，需要一个index记录起始位置
### 代码

```java
class Solution {
    public List<List<Integer>> findSubsequences(int[] nums) {
        Set<List<Integer>> set = new HashSet<>();
        dfs(nums,new ArrayList<Integer>(), set, 0);
        return new ArrayList<>(set);
    }

    private void dfs(int[] nums, List<Integer> tempList, Set<List<Integer>> ans, int index) {
        if (tempList.size() > 1)
            ans.add(new ArrayList<>(tempList));
        for (int i = index; i < nums.length; i++){
            if (tempList.size() == 0 || tempList.get(tempList.size()-1) <= nums[i]){
                tempList.add(nums[i]);
                dfs(nums,tempList,ans,i+1);
                tempList.remove(tempList.size()-1);
            }
        }
    }
}
```