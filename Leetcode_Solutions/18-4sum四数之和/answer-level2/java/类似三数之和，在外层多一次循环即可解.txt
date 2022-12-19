# 核心思路
--------------------------------------------------------------------
>采用四个指针的形式，前两个遍历，后面两个用了检验数据是否正确.
>> ### 注意点:
>> . 不能重复，尽量遍历过的不能重新遍历
>> . 后两个指针从头和尾分别开始，减少时间复杂度。
>
>>### 指针活动范围：
>>1、i指针从0开始到倒数第三个；
>>2、j指针从i后面开始到倒数第二个；
>>3、left从前往后，right从后往前，活动范围是从j开>始到最后，left和right类似两数之和的问题。
# 代码如下：
--------------------------------------------------------------------
```
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {

        List<List<Integer>> result = new ArrayList<>();
        //先排序
        Arrays.sort(nums);

        for (int i = 0;i < nums.length - 2;i ++) {
            // 去除指针i可能的重复情况
            if (i != 0 && nums[i] == nums[i-1]) {
                continue;
            }
            for (int j = i + 1;j < nums.length;j ++) {
                // 去除j可能重复的情况
                if (j != i + 1 && nums[j] == nums[j-1]) {
                    continue;
                }

                int left = j + 1;
                int right = nums.length -1;

                while (left < right) {
                    // 不满足条件或者重复的，继续遍历
                    if ((left != j + 1 && nums[left] == nums[left-1]) || nums[i] + nums[j] + nums[left] + nums[right] < target) {
                        left ++;
                    } else if ((right != nums.length -1 && nums[right] == nums[right + 1]) || nums[i] + nums[j] + nums[left] + nums[right] > target) {
                        right --;
                    } else {
                        List<Integer> list = new ArrayList<>();
                        list.add(nums[i]);
                        list.add(nums[j]);
                        list.add(nums[left]);
                        list.add(nums[right]);

                        result.add(list);
                        // 满足条件的，进入下一次遍历
                        left ++;
                        right --;
                    }
                }

            }
        }

        return result;
    }
}
