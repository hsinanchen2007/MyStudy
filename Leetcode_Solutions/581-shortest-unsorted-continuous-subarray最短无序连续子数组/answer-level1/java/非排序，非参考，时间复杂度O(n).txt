在开头遍历找到第一个降序的位置，往前的区域定义为S，从结尾遍历找到第一个升序的位置，往后的区域定义为E
这里还需要考虑有重复值得情况，因此S区域还要根据最后一个值前面是否有重复的情况，往前缩小S，E同理
然后在中间这段序列里边找到这里边的最大值，最小值。
使用最小值在S区域里，从开始找第一个大于最小值得位置s，使用最大值在E区域里，从尾开始找第一个小于最大值的位置e
最终的结果是e - s + 1
代码有些冗长，但是好理解

```
class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int s = -1;
        int e = -1;
        for(int i = 0; i < nums.length - 1; i++){
            if(nums[i] > nums[i + 1]){
                s = i;
                break;
            }
        }
        while(s > 0 && nums[s] == nums[s - 1]) s--;
        
        if(s == -1) return 0;
        for(int i = nums.length - 1; i > 0; i--){
            if(nums[i] < nums[i - 1]){
                e = i;
                break;
            }
        }
        while(e < nums.length - 1 && nums[e] == nums[e + 1]) e++;
        
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
       for(int i = s; i <= e; i++){
           if(min > nums[i])
               min = nums[i];
           if(max < nums[i])
               max = nums[i]; 
       }
        int res_s = -1, res_e = -1;
        for(int i = 0; i <= s; i++){
            if(nums[i] > min){
                res_s = i;
                break;
            }
        }
        for(int i = nums.length - 1; i >= e; i--){
            if(nums[i] < max){
                res_e = i;
                break;
            }
        }
        return res_e - res_s + 1;
    }
}
```