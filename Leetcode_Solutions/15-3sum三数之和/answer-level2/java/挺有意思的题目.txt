### 解题思路
1. 先排序
2. 排序后用双下标动态比较

### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        for(int i = 0;i< nums.length - 2;i++){
            int j = i + 1;
            int k = nums.length - 1;
            while (j < k){
                int temp = nums[i] + nums[j] + nums[k];
                if (temp == 0){
                    List<Integer> list = new ArrayList<>();
                    list.add(nums[i]);
                    list.add(nums[j]);
                    list.add(nums[k]);
                    res.add(list);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j-1])
                        j++;
                    while (j < k && nums[k] == nums[k+1])
                        k--;
                }
                else if (temp > 0)
                    k--;
                else
                    j++;
            }
        }
        Set<List<Integer>> set = new HashSet<>(res);
        return new ArrayList<>(set);
    }
}
```