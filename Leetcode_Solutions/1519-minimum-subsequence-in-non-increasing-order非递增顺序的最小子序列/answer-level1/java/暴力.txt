* 先排序下
* 倒序遍历当前和是否大于剩余和，并去符合条件的元素
# 代码
```
class Solution {
    public List<Integer> minSubsequence(int[] nums) {
        Arrays.sort(nums);
        int sum = Arrays.stream(nums).sum();
        List<Integer> list = new ArrayList<>();
        int scur = 0;
        for(int i = nums.length-1;i >= 0;i--){
            scur += nums[i];
            if(scur > sum - scur){
                list.add(nums[i]);
                break;
            }else{
                list.add(nums[i]);
            }
        }
        return list;
    }
}
```

