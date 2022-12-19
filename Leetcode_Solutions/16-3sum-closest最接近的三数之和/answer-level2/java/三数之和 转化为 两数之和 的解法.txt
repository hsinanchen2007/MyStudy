跟三数之和那道题一样，这道题也可以分解为求固定一个数，然后求两个数的和的最接近的值

同理，还可以扩展到最接近的n数之和问题

直接上代码，代码注释应该比较清晰了

```java
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int ans = 0x3f3f3f3f;
        // 排序，正常操作
        Arrays.sort(nums);

        for(int i = 0; i < nums.length - 2; i++){
            if(i > 0 && nums[i] == nums[i - 1]){
                // 如果当前target指向的值与前一个相同，说明这个值以及被计算过了，
                // 为了避免冗余，直接跳过
                continue;
            }

            int ans_temp = TwoSum(nums,i + 1, nums.length - 1, i, target);
            // 更新结果，用更小差值的和来更新
            if(Math.abs(target - ans) > Math.abs(target - ans_temp)){
                ans = ans_temp;
            }
        }
        return ans;
    }

    private int TwoSum(int[] nums, int begin, int end, int cur, int target){
        // 定义最终返回的解
        // 设定为一个很大的值
        int difference = 0x3f3f3f3f;
        int ans = 0x3f3f3f3f;
        int left = begin;
        int right = end;
        int target_num = target - nums[cur];

        // 正式的找解的过程
        while(left < right){
            // 定义一个临时变量，用于记录当前左右指针指向的数的和与target_num之间的差值。
            // 注意，这里的target_num不等于题目的target，是自己定义的一个临时变量，用于将问题转化为 Two Sum Closet 问题
            int temp_dif = nums[left] + nums[right] - target_num;
            
            // 发现这个差值比前面一次的差值要小，则更新返回的和，以及差值
            // 这里比较差值用了绝对值，因为只有绝对值小才是真的差异小。
            
            if(Math.abs(temp_dif) < difference){
                ans = nums[left] + nums[right] + nums[cur];
                difference = Math.abs(temp_dif);
            }
            
            // 这里更新左右指针，试图寻找到一个和target_num差值较小的数
            // 这里没有利用绝对值，是为了利用差值的正负性来更新指针的移动方向
            // 有点梯度下降的味道
            if(temp_dif > 0){
                // 和过大，因此右指针左移
                right--;
            }else if(temp_dif < 0){
                // 和过小，因此左指针右移
                left++;
            }else {
                // 找到了一个恰好等于target的组合，差值为0.可以直接返回
                break;
            }
        }
        return ans;
    }
}
```
