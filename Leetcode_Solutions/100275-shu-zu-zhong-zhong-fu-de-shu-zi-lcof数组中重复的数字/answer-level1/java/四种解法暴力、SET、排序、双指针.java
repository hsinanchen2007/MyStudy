```
class Solution {
    //暴力方法不讲了，两层循环比较，太蠢。
    
    /*
    第一种解法，时间优先解法。使用set 这种找重复的问题很容易想到的思路。
    public int findRepeatNumber(int[] nums) {
        Set<Integer> set = new HashSet<>() ;
        for(int i=0;i<nums.length;i++){
            int flag = set.size() ;
            set.add(nums[i]) ;
            if(flag==set.size()){
                return nums[i] ;
            }
        }
        return -1 ;
    }
    */


    /*
    第二种解法排序加双指针的思路。空间优先解法。
    这种完全也是为了用双指针而用双指针锻炼下思路。
    应该还会有优化的空间 大神指正。
    会有特殊情况超时。
    public int findRepeatNumber(int[] nums) {
        Arrays.sort(nums) ;
        for(int left=0;left<nums.length;left++){
            int right = nums.length-1 ;
            while(left<right){
                if(nums[left]==nums[right]){
                    return nums[left] ;
                }else if(nums[left]!=nums[right]){
                    right-- ;
                }
            }
        }
        return -1 ;
   }
   */

   public int findRepeatNumber(int[] nums) {
       //最简单的一种思路 没啥好说的排序 判断相邻的两个数是不是相等
       //相等则返回结果。
       Arrays.sort(nums) ;
       for(int i=0;i<nums.length-1;i++){
           if(nums[i]==nums[i+1]){
               return nums[i] ;
           }
       }
       return -1 ;
   }
}
```
算法重要的思路而不是代码细节，锻炼思路很重要！