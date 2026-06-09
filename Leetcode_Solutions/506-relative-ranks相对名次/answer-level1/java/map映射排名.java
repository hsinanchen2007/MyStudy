### 解题思路
先复制一个数组进行排序，然后用map进行映射排名。

### 代码

```java
class Solution {
    public String[] findRelativeRanks(int[] nums) {
        Map<Integer,Integer> map = new HashMap<>();
        String[] ans = new String[nums.length];
        int[] copyNums = nums.clone();
        Arrays.sort(copyNums);
        for(int i = 0;i<copyNums.length;i++){
            map.put(copyNums[i],copyNums.length-i);
        }
        for(int i = 0;i<nums.length;i++){
            if(map.get(nums[i]) == 1){
                ans[i] = "Gold Medal";
            }else if(map.get(nums[i]) == 2){
                ans[i] = "Silver Medal";
            }else if(map.get(nums[i]) == 3){
                ans[i] = "Bronze Medal";
            }else{
                ans[i] = String.valueOf(map.get(nums[i]));
            }
        }
        return ans;
    }
}
```