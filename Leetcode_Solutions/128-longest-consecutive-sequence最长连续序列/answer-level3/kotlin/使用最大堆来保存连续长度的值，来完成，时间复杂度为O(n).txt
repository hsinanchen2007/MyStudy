```java []
public int longestConsecutive(int[] nums) {

    if (nums.length < 1) {
      return 0;
    }
    if (nums.length == 1) {
      return 1;
    }
    //排序
    Arrays.sort(nums);

    // 使用最大堆来保存连续长度的值
    PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
    int count = 1;
    for (int i = 0; i < nums.length - 1; i++) {
      //去重
      if (nums[i + 1] != nums[i]) {
        // 如果是连续的值，则连续长度直接加1
        if (nums[i + 1] - nums[i] == 1) {
          count++;
        } else {
          // 如果不是连续的值，则连续长度置为1
          count = 1;
        }
      }
      maxHeap.offer(count);
    }
    return maxHeap.peek();
  }
```

```kotlin []
fun longestConsecutive(nums: Array<Int>): Int {

        if (nums.isEmpty()) {
            return 0
        }
        if (nums.size == 1) {
            return 1
        }

        Arrays.sort(nums)

        // 使用最大堆来保存连续长度的值
        val maxHeap = PriorityQueue<Int> { a, b -> b!! - a!! }
        var count = 1
        for (i in 0 until nums.size - 1) {
            // 如果是连续的值，则连续长度直接加1
            if (nums[i + 1] != nums[i]) {
                if (nums[i + 1] - nums[i] == 1) {
                    count++
                } else {
                    // 如果不是连续的值，则连续长度置为1
                    count = 1
                }
            }
            maxHeap.offer(count)
        }
        return maxHeap.peek()
    }
```