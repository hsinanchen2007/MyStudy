- 排序
- 求总和
- 从后往前取大的值，直到和大于总和的一半

```
class Solution {
    public List<Integer> minSubsequence(int[] nums) {
        Arrays.sort(nums);
        int i=0, j=nums.length-1;
        int sum=0, sum_right=0;
        List<Integer> ans = new ArrayList<>();
        for(i=0; i<nums.length; i++){
            sum += nums[i];
        }
        i = 0;
        while(sum_right <= sum/2){
            ans.add(nums[j]);
            sum_right += nums[j];
            i++;
            j--;
        }
        return ans;
    }
}
```
