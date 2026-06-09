### 解题思路
类似组合数思路，重点在先对nums进行排序，在递归中，遇见重复数字跳过即可

### 代码

```java
class Solution {
    private List<List<Integer>> res;
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        res = new ArrayList<>();
        if(nums.length == 0) return res;
        Arrays.sort(nums);
        findSet(nums, 0, nums.length, new Stack<Integer>());
        return res;
    }
    public void findSet(int[] nums, int start, int count, Stack<Integer> tmp){
        if(count != 0){
            res.add(new ArrayList(tmp));
        }else{
            res.add(new ArrayList(tmp));
            return;
        }
        for(int i = start; i < nums.length; i++){
            if(i > start && nums[i] == nums[i - 1]) continue;
            tmp.push(nums[i]);
            findSet(nums, i + 1,  count - 1, tmp);
            tmp.pop();
        }
    }
}
```