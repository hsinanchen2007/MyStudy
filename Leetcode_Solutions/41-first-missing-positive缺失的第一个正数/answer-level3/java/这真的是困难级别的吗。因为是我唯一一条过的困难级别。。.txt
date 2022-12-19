执行结果：
通过
显示详情
执行用时 :2 ms, 在所有 Java 提交中击败了77.43%的用户
内存消耗 :35.6 MB, 在所有 Java 提交中击败了85.53%的用户

```
class Solution {
    public int firstMissingPositive(int[] nums) {
        Arrays.sort(nums);
        int NOtShowMin=1;
        int len=nums.length;
        for(int i=0;i<len;i++){
            if(nums[i]==NOtShowMin){
                NOtShowMin++;
            }
        }
        return NOtShowMin;
    }
}
```
