1. 先排序
2. 因为数组有序，可以使用两个指针`start`和`end`指向数组的头部和尾部
    1. 如果`nums[start] + nums[end] > target`，说明需要更大的元素，`start++`
    2. 如果`nums[start] + nums[end] < target`，说明需要更小的元素，`end--`
    3. 如果`nums[start] + nums[end] == target`，说明符合条件，将`start`和`end`加入结果中
~~~java
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

class Solution {
    public List<List<Integer>> pairSums(int[] nums, int target) {
        List<List<Integer>> ans = new LinkedList<>();
        Arrays.sort(nums);
        int start = 0;
        int end = nums.length - 1;
        for (; start < end; ) {
            int sum = nums[start] + nums[end];
            if (sum < target) {
                start++;
            } else if (sum > target) {
                end--;
            } else {
                List<Integer> list = new LinkedList<>();
                list.add(nums[start]);
                list.add(nums[end]);
                ans.add(list);
                start++;
                end--;
            }
        }
        return ans;
    }
}
~~~
* 时间复杂度为`O(NlogN + N)`
* 空间复杂度为`O(1)`