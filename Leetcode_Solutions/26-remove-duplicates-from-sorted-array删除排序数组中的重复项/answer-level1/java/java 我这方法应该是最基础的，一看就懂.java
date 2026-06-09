我这方法是不是很垃圾？一想就想到了，有没有大佬来说一下我的方法的缺陷啊
```
class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums==null || nums.length<=0) return 0;
        int count=1;
        int tempNum=nums[0];
        for(int i=1;i<nums.length;i++){
            if(tempNum==nums[i]){//重复数字，找下一个没出现过的数字
                continue;
            }
            nums[count++]=nums[i];//当前出现了不一样的数字
            tempNum=nums[i];//继续下一个不一样的数字
        }
        return count;
    }
}
```
