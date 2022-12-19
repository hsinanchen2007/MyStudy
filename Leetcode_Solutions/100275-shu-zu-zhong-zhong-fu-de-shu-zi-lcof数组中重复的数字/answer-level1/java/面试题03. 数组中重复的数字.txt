1. 思路一：遍历
最暴力、最直接的方法就是遍历数组了，只不过效率很低。
开销：
时间复杂度为O(n^2),空间复杂度为O(1)。
不改变原来的数组。
```
class Solution {
    public int findRepeatNumber(int[] nums) {
        // 遍历
        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] == nums[j]) {
                    return nums[i];
                }
            }
        }
        return -1;
    }
}
```
2. 思路二：哈希
用哈希表来查重,向HashSet或者HashMap中插入元素，检查是否重复插入。评论区的标记数组法，思路其实也是一样的。
开销：
时间复杂度为O(n),空间复杂度为O(n)。
不改变原来的数组。
```
class Solution {
    public int findRepeatNumber(int[] nums) {
        // 哈希表
        Map<Integer, Integer> hashMap = new HashMap<>();
        for (int num : nums) {
            // put(key,value)返回值为oldValue或者null
            // 当返回值不为null，则当前key已经插入过，即为重复值
            if (hashMap.put(num, 1) != null)
                return num;
        }
        return -1;
    }
}
```
3. 思路三：排序
先将数组排序，排序后遍历一遍，比较相邻的元素是否重复。
开销：
时间复杂度为O(nlogn) -> 排序时间复杂度为O(nlogn)，遍历的时间复杂度为O(n)。
空间复杂度为O(1)
改变了原来的数组。
```
class Solution {
    public int findRepeatNumber(int[] nums) {
        // 排序
        Arrays.sort(nums);
        for (int i = 0; i <= nums.length - 2; i++) {
            if (nums[i] == nums[i + 1]) {
                return nums[i];
            }
        }
        return -1;
    }
}
```