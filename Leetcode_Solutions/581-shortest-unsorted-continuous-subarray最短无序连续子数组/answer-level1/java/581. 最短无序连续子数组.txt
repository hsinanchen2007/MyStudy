/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/25
 *
 * 解题思路: 使用两个数组 记录从前向后的当前最大值 从后向前的当前最小值
 *
 * 从后向前遍历 如出现当前的值小于他之前的最大值，则停止记录end
 * 从前向后遍历 如出现当前的值大于他之后的最小值，则停止记录start
 *
 * return end - start + 1> 0 ? end - start + 1:0
 *
 * 注意：如果是一个数字 直接返回
 *
 *
 */

```
public int findUnsortedSubarray(int[] nums) {
    if(nums.length == 1) return 0;
    
    int[] max = new int[nums.length];
    int[] min = new int[nums.length];

    int max_v = nums[0];
    int min_v = nums[nums.length - 1];
    int start = 0;
    int end = nums.length - 1;
    int i = 0;
    for(i = 0;i < nums.length;i++){
        if(nums[i] > max_v){
            max_v= nums[i];
        }
        max[i] = max_v;
    }

    //最小
    for(i = nums.length - 1;i >= 0;i--){
        if(nums[i] < min_v){
            min_v= nums[i];
        }
        min[i] = min_v;
    }

    for(i = 0;i < nums.length;i++){
        start = i;
        if(nums[i] > min[i]){
            break;
        }
    }
    for(i = nums.length - 1;i >= 0;i--){
        end = i;
        if(nums[i] < max[i]){
            break;
        }
    }


    return end - start + 1> 0 ? end - start + 1:0;
}
```