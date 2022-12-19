#### 双指针法的解题思路

- 先让数组有序，也就是需要先对数组进行排序
- 然后每次固定一个元素，再去寻找另外两个元素，也就是双指针

#### 双指针法的代码实现

- 利用 `Arrays.sort(nums)` 对数组进行排序。
- 初始化一个用于保存结果的值 `result = nusm[0] + nums[1] + nums[2]` （不要自己设初值，直接从数组中抽取三个元素，假设这是最接近的三数之和，然后再更新就是了）。
- 利用下标 `i` 对数组进行遍历，此时就是在固定第一个元素，注意，下标 `i` 的边界为 `i < nums.length-2`，否则设置指针的时候会出现数组越界。
- 每次遍历的过程中设置两个指针，分别是 `left = i + 1`、`right = nums.length - 1`。
- 检查 `sum = nums[i] + nums[left] + nums[right]`与 `target` 的距离，如果该距离比之前保存的 `result` 与 `target` 的距离更小，就更新 `result`。
- 然后就是移动双指针。
- 如果 `sum` 的值比 `target` 大，那么我们让 `right--`，因为数组是有序的，`right` --会使得下一次的 `sum` 更小，也就更接近 `target` 的值
- 同理，如果 `sum` 的值 `target` 小，那么我们让 `left++`。·
- `left++` 和 `right--` 的界限自然是 `left != right`，如果 `left == right`，说明我们已经将所有的元素都遍历过一遍了。
- 重复上面的操作，直到i循环结束为止，返回 `result`。

下面是具体的代码实现，简单，但是效率也不高，还可以进行一些优化

```java [-Java]
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int result = nums[0] + nums[1] + nums[2];
        for(int i=0;i<nums.length-2;i++){
            int left = i+1;
            int right = nums.length - 1;
            while(left != right){
                int sum = nums[i] + nums[left] + nums[right];
                if(Math.abs(sum - target) < Math.abs(result - target))
                    result = sum;
                if(sum > target){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return result;
    }
}
```

#### 双指针法的优化


1. 元素重复的问题

- 举个例子，`nums = [1,1,1,2,3] target = 7`，那么最终的结果应该是 `6 (1 + 2 + 3)`。
- 但是按照上面的代码，在遍历的时候 `nums[i]`会重复的等于 1 这个数，但是其实之前 `nums[i]` 等于 1 已经遍历过了，后面的遍历都属于无用的遍历。
- 所以可以添加去重的操作

```java [-Java]
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int result = nums[0] + nums[1] + nums[2];
        for(int i=0;i<nums.length-2;i++){
            int left = i+1;
            int right = nums.length - 1;
            while(left != right){
                int sum = nums[i] + nums[left] + nums[right];
                if(Math.abs(sum - target) < Math.abs(result - target))
                    result = sum;
                if(sum > target){
                    right--;
                    // 解决nums[right]重复
                    while(left != right && nums[right] == nums[right+1])
                        right--;
                }
                else{
                    left++;
                    // 解决nums[left]重复
                    while(left != right && nums[left] == nums[left-1])
                        left++;
                }
            }
            // 解决nums[i]重复
            while(i<nums.length-2 && nums[i] == nums[i+1])
                i++;
        }
        return result;
    }
}
```
2. 超越界限的问题

- 举个例子，`nums = [-3,-1,3,4,5]`。
- 假设 `i = 0`，`left = 1`，`right = 4`，那么每次 `left` 和 `right` 之间都有许多元素，那么 `left` 和 `right` 之间的元素之和肯定也有一个最小值和一个最大值。
- 就如同 `left = 1`，`right = 4`，那么移动指针的情况下，`nums[left] + nums[right]` 的最小值肯定为 `nums[left] + nums[left + 1]`，因为这两个元素是 `left` 和 `right` 范围内能取到的最小的两个元素，同理可证最大值。
- 如果 `target` 的值比 `nums[i] + nums[left] + nums[left + 1]` 的值还小，那么双指针无论怎么取，最后都会取到 `nums[i] + nums[left] + nums[left + 1]`。
- 同理可证 `target` 的值比`nums[i] + nums[right] + nums[right - 1]` 的值还大的情况。
- 所以可以增加一个判断，满足条件的情况下就可以直接取值，而不需要双指针一步步的判断来进行取值，减少了双指针的移动。

```java [-Java]
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int result = nums[0] + nums[1] + nums[2];
        for(int i=0;i<nums.length-2;i++){
            int left = i+1;
            int right = nums.length - 1;
            while(left != right){
                // 判断最小值
                int min = nums[i] + nums[left] + nums[left + 1];
                if(target < min){
                    if(Math.abs(result - target) > Math.abs(min - target))
                        result = min;
                    break;
                }
                //判断最大值
                int max = nums[i] + nums[right] + nums[right - 1];
                if(target > max){
                    if(Math.abs(result - target) > Math.abs(max - target))
                        result = max;
                    break;  
                }
                int sum = nums[i] + nums[left] + nums[right];
                if(Math.abs(sum - target) < Math.abs(result - target))
                    result = sum;
                if(sum > target){
                    right--;
                    while(left != right && nums[right] == nums[right+1])
                        right--;
                }
                else{
                    left++;
                    while(left != right && nums[left] == nums[left-1])
                        left++;
                }
            }
            while(i<nums.length-2 && nums[i] == nums[i+1])
                i++;
        }
        return result;
    }
}
```

3. 三数之和等于 target 的问题

- 举个例子，`nums = [1,1,2,3,4,5,6,10] target = 12`，那么最终的结果应该是 `12 (1 + 1 + 10)`。
- 有些时候，可能会直接找到三数之和等于 `target` 的情况，此时直接返回结果即可，不需要在进行之后的循环，因为不可能有数比他自己更接近自己了。  

```java [-Java]
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int result = nums[0] + nums[1] + nums[2];
        for(int i=0;i<nums.length-2;i++){
            int left = i+1;
            int right = nums.length - 1;
            while(left != right){
                int min = nums[i] + nums[left] + nums[left + 1];
                if(target < min){
                    if(Math.abs(result - target) > Math.abs(min - target))
                        result = min;
                    break;
                }
                int max = nums[i] + nums[right] + nums[right - 1];
                if(target > max){
                    if(Math.abs(result - target) > Math.abs(max - target))
                        result = max;
                    break;  
                }
                int sum = nums[i] + nums[left] + nums[right];
                // 判断三数之和是否等于target
                if(sum == target)
                    return sum;
                if(Math.abs(sum - target) < Math.abs(result - target))
                    result = sum;
                if(sum > target){
                    right--;
                    while(left != right && nums[right] == nums[right+1])
                        right--;
                }
                else{
                    left++;
                    while(left != right && nums[left] == nums[left-1])
                        left++;
                }
            }
            while(i<nums.length-2 && nums[i] == nums[i+1])
                i++;
        }
        return result;
    }
}
```

有图有真相

![](https://pic.leetcode-cn.com/024c4bfa0658ec3baf23fa9aa68f91c886352d849c0b96671b9aa3a9167727c7-image.png){:width=400}
{:align=center}






