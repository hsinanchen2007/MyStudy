这个题，首先分两步走。
第一步就是先找出数组中的最大值，并记录该最大值的索引；
第二部，判断该值是否至少是其他数字的两倍多。
所以，我们有了以下代码：
```java
class Solution {
    public int dominantIndex(int[] nums) {
        
        //先找出数组中的最大元素
        if(nums==null||nums.length==0){
            return -1;
        }
        
        int max = nums[0];
        int index=0;
        for(int i=1;i<nums.length;i++){
            if(nums[i]>=max){
                max = nums[i];
                index = i;
            }
        }
        //再判断该max值是否是每个值的2倍
        for(int j = 0; j<nums.length;j++){
            if( nums[j]*2 > max && nums[j]!=max){
                return -1;
            }
        }
        return index;
    }
}
```
时间复杂度：O(n)
空间复杂度：O（1）
耗时：2ms
内存：35m