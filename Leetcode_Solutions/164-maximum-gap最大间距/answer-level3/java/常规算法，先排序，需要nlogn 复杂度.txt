执行结果：
通过
显示详情
执行用时 :
7 ms
, 在所有 Java 提交中击败了
43.82%
的用户
内存消耗 :
38.4 MB
, 在所有 Java 提交中击败了
54.89%
的用户```
class Solution {
    public int maximumGap(int[] nums) {
        Arrays.sort(nums);
        int len = nums.length;
        if(len<2)return 0;
        int max=0;
        for(int i=1;i<len; i++){
            if(nums[i]-nums[i-1]>max){
                max=nums[i]-nums[i-1];
            }
        }
        return max;
    }
}
```
