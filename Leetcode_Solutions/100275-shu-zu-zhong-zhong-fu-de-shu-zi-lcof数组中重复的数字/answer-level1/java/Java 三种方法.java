把书上的讲的三种方法搬过来了，方便查看。
## 方法一：数组排序
先把数组进行排序，即可很容易地找出答案。对一个长度为 n 的数组排序最少需要 O(nlogn) 的时间。
``` Java
class Solution {
    public int findRepeatNumber(int[] nums) {
        Arrays.sort(nums);
        for (int i = 1; i < nums.length; i ++) {
            if (nums[i - 1] == nums[i]) {
                return nums[i];
            }
        }
        return -1;
    }
}
```
## 方法二：哈希表
顺序扫描数组，每扫描一个数字，用 O(1) 的时间判断哈希表中是否已包含该数字。若还没包含，则加入哈希表；若已包含，则找到一个重复数字。
时间复杂度 O(n)，空间复杂度 O(n)。
``` Java
class Solution {
    public int findRepeatNumber(int[] nums) {
        Set<Integer> set = new HashSet<Integer>();
        for (int num : nums) {
            if (!set.add(num)) {
                return num;
            }
        }
        return -1;
    }
}
```
## 方法三：
注意到：数组长度为 n，数字都在 0~n-1 的范围内。因此如果数组内没有重复数字，那么排序后数字 i 将出现在下标为 i 的位置。
**具体操作：** 扫描数组，当扫描到下标为 i 的数字（用 m 表示）时，比较这个数字 m 是否等于 i，若是则继续扫描，若不是则将其与下标为 m 的数字进行比较。如果它与下标为 m 的数字相等，则找到了；若不相等，就将下标为 i 的数字与下标为 m 的数字进行交换，把 m 放到属于它的位置。重复如此，直至结束。
时间复杂度 O(n)，空间复杂度 O(1)。
``` Java
class Solution {
    public int findRepeatNumber(int[] nums) {
        for (int i = 0; i < nums.length; i ++) {
            while(nums[i] != i){
                if (nums[i] == nums[nums[i]]) {
                    return nums[i];
                }
                // 交换nums[i]和nums[nums[i]]
                int temp = nums[i];
                nums[i] = nums[temp];
                nums[temp] = temp;
            }
        }
        return -1;
    }
}
```
