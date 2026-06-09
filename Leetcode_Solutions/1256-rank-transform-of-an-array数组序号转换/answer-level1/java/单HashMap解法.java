### 解题思路
先克隆数组，然后通过排序，用hash表记录次序

### 代码

```java
class Solution {
    public int[] arrayRankTransform(int[] arr) {
        if (arr.length == 0) return arr;
        int[] nums = Arrays.copyOf(arr, arr.length);
        Arrays.sort(nums);
        Map<Integer, Integer> map = new HashMap<>();
        // 次序
        int index = 1;
        map.put(nums[0], index);
        for (int i = 1; i < nums.length; i++) {
            // 如果和上个数不一致就增加次序
            if (nums[i] != nums[i - 1]) map.put(nums[i], ++index);
        }

        for (int i = 0; i < arr.length; i++) arr[i] = map.get(arr[i]);

        return arr;
    }
}
```