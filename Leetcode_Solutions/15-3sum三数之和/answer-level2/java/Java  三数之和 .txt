此三数之和 Java题解 基本出自[@zhu_shi_fu](/u/zhu_shi_fu/)的解法


```
public List<List<Integer>> threeSum(int[] nums) {
        //排序
        Arrays.sort(nums);
        List<List<Integer>> list = new ArrayList<>();
        int L, R;
        a:for (int i = 0; i < nums.length-2; i++) {
            //若上一个数和当前数相同 加一跳过
            while (i != 0 && nums[i-1] == nums[i]){
                i++;
                if (i > nums.length-2){
                    break a;
                }
            }
            //小, 大指针
            L = i+1;
            R = nums.length-1;

            while (L < R){
                if (nums[L] + nums[i] + nums[R] == 0) {
                    //等于0
                    list.add(Arrays.asList(nums[L], nums[i], nums[R]));

                    // 最大指针左移到第一个不同于 当前最大指针的值 避免重复
                    // 最小指针右移到第一个不同于 当前最小指针的值 避免重复
                    while (L < R && nums[R-1] == nums[R]){
                        R--;
                    }
                    R--;
                    while (L < R && nums[L+1] == nums[L]){
                        L++;
                    }
                    L++;

                } else if (nums[L] + nums[i] + nums[R] > 0) {
                    //大于零 最大指针左移到第一个不同于 当前最大指针的值 避免重复
                    while (L < R && nums[R-1] == nums[R]){
                        R--;
                    }
                    R--;

                } else {
                    //小于零 最小指针右移到第一个不同于 当前最小指针的值 避免重复
                    while (L < R && nums[L+1] == nums[L]){
                        L++;
                    }
                    L++;

                }
            }
        }
        return list;
    }
```
