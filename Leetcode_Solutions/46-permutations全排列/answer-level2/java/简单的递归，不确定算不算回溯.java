### 解题思路
计算出除了当前元素的其他元素组成的数组的全排列，每个排列再加上当前元素

### 代码

```java
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        if (nums.length==0){
            return ans;
        }
        if (nums.length == 1) {
            List<Integer> t = new ArrayList<>();
            t.add(nums[0]);
            ans.add(t);
            return ans;
        }
        for(int i=0;i<nums.length;i++){
            int[] ints = new int[nums.length - 1];
            for(int j=0;j<nums.length;j++){
                if(j!=i){
                    ints[j>i?j-1:j] = nums[j];
                }
            }
            for(List<Integer> list:permute(ints)){
                list.add(nums[i]);
                ans.add(list);
            }
        }
        return ans;
    }
}
```