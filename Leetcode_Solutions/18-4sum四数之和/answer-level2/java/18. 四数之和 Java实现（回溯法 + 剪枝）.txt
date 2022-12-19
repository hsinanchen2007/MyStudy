### 解题思路
    没用双指针用回溯法效率比较低，开始做了排序处理，这一题回溯法比较难处理的是剪枝和去重，剪枝条件要选好不然会超时，去重的话添加答案的时候用ArrayList的equals方法即可。

### 代码

```java
class Solution {
    private int curSum;

    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        List<Integer> curList = new ArrayList<>();
        List<List<Integer>> ansList = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            curList.add(nums[i]);
            this.curSum += nums[i];
            BackTracking(curList, ansList, nums, i + 1, target);
            this.curSum -= nums[i];
            curList.remove(curList.size() - 1);
        }
        return ansList;
    }

    private void BackTracking(List<Integer> curList, List<List<Integer>> ansList, int[] nums, int idx, int target) {
        if (curList.size() == 4) {
            if (this.curSum == target && !hasAns(ansList, curList)) {
                ansList.add(new ArrayList<Integer>(curList));
            }
            return;
        }
        if (idx >= nums.length) {
            return;
        }
        if (this.curSum > target && nums[idx] > 0) {
            return;
        }
        curList.add(nums[idx]);
        this.curSum += nums[idx];
        BackTracking(curList, ansList, nums, idx + 1, target);
        this.curSum -= nums[idx];
        curList.remove(curList.size() - 1);
        BackTracking(curList, ansList, nums, idx + 1, target);
        return;
    }
    
    private boolean hasAns(List<List<Integer>> ansList, List<Integer> curList) {
        for (List<Integer> l : ansList) {
            if (l.equals(curList)) {
                return true;
            }
        }
        return false;
    }
}
```