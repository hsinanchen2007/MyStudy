## 解法1
```
   Arrays.sort(nums);
        int result = nums[0] + nums[1] + nums[2];
        int diff = Integer.MAX_VALUE;
        for (int i = 0; i < nums.length-2; i++){
            int left = i + 1;
            int right = nums.length - 1;
            while (left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < target){
                    left++;
                }else if(sum > target){
                    right--;
                }else{
                    result = target;
                    return result;
                }
                if (Math.abs(sum -target) < diff){
                    diff = Math.abs(sum -target);
                    result = sum;
                }
            }
        }
        return result;
```
上面是最基本最正宗的解法，耗时11ms左右。

## 优化后解法2
当有相同数字时，如第i个等于第i-1个，进行剪枝操作跳过当前的i。
```
public int threeSumClosest2(int[] nums, int target) {
        Arrays.sort(nums);
        int result = nums[0] + nums[1] + nums[2];
        int diff = Integer.MAX_VALUE;
        for (int i = 0; i < nums.length - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue; //剪枝去重

            int left = i + 1;
            int right = nums.length - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    result = target;
                    return result;
                }
                if (Math.abs(sum - target) < diff) {
                    diff = Math.abs(sum - target);
                    result = sum;
                }
            }
        }
        return result;
    }
```
经过优化后时间缩短到5ms。

## 优化后解法3
在上面2的基础上还可以进一步优化，排序后的数组对给定的索引i，在[left, right]区间内，最大值 rangeMax = nums[i] + nums[right] + nums[right - 1]，最小值为 rangeMin = nums[i] + nums[left] + nums[left + 1]。如果最小值都比target大，那left右边的数一定比target大也就没有必要比下去了。因此只需判断rangeMin和target之间的diff是否最小，如果小的话更新diff和result。同理，针对区间内的最大值rangeMax如果它都比target小的话，那right右边的肯定都比target小，也没有比的必要了。只需要判断rangeMax和target之间的diff关系就行了。
**总之：rangeMin和rangeMax是两种极端情况，让程序不再做无谓的循环比较。**
```
public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int result = nums[0] + nums[1] + nums[2];
        int diff = Integer.MAX_VALUE;
        for (int i = 0; i < nums.length - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = nums.length - 1;

            int rangeMin = nums[i] + nums[left] + nums[left + 1];
            int rangeMax = nums[i] + nums[right] + nums[right - 1];

            if (rangeMin > target) {
                if (Math.abs(rangeMin - target) < diff) {
                    diff = Math.abs(rangeMin - target);
                    result = rangeMin;
                }
                continue;
            } else if (rangeMax < target) {
                if (Math.abs(rangeMax - target) < diff) {
                    diff = Math.abs(rangeMax - target);
                    result = rangeMax;
                }
                continue;
            }

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    result = target;
                    return result;
                }
                if (Math.abs(sum - target) < diff) {
                    diff = Math.abs(sum - target);
                    result = sum;
                }
            }
        }
        return result;
    }
```
上述代码执行时间缩短到2ms。