两种解法，利用Set或者利用哈希表原理
```java
import java.util.HashSet;
import java.util.Set;

/**
 * 解法一：利用Set集合不可添加重复元素特性筛选，需额外Set集合辅助
 */
class Solution {
    public int findRepeatNumber(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for(int i:nums){
            if(!set.add(i)){
                return i;
            }
        }
        return -1;
    }
}
```

```java
/**
 * 利用哈希表特性，时间复杂度低，但会改变原数组
 */
class Solution {
    public int findRepeatNumber(int[] nums) {
        /**
         * 将该数组用作哈希表存储元素，发生哈希冲突则说明有重复
         * 对应下角标，即nums[i]的值应该为i => nums[i]=i
         * 开始遍历数组
         */
        for (int i = 0; i < nums.length; i++) {
            while (nums[i] != i) {
                /**
                 * 发生哈希冲突
                 */
                if (nums[nums[i]] == nums[i]) {
                    return nums[i];
                } else {
                    /**
                     * 交换，将值为i的元素放入角标为i的位置，即nums[nums[i]]=nums[i]
                     */
                    swap(nums, nums[i], i);
                }

            }
        }
        return -1;
    }

    private void swap(int[] arr, int a, int b) {
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }
}
```