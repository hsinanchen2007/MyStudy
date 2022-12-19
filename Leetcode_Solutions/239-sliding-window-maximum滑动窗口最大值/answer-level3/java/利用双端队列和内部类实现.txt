```java
public int[] maxSlidingWindow(int[] nums, int k) {
     if (nums.length == 0) {
      return new int[0];
    }
    int[] arr = new int[nums.length - k + 1];

    Deque<Inner> deque = new ArrayDeque<>();
    int temp = 0;

    for (int i = 0; i < nums.length; i++) {

      Inner inner = new Inner(nums[i], i);
      deque.addLast(inner);

      // 移除已经过时的元素
      if (deque.getFirst().index == i - k) {
        deque.removeFirst();
      }

      Iterator<Inner> iterator = deque.iterator();
      while (iterator.hasNext()) {
        if (iterator.next().value < nums[i]) {
          iterator.remove();
        }
      }

      // 在满足k个之后才开始添加
      if (i >= k - 1) {
        arr[temp++] = deque.getFirst().value;
      }
    }
    return arr;
  }

  class Inner {

    Integer value;  // 记录值
    Integer index;  // 记录下标位置

    private Inner(Integer value, Integer index) {
      this.value = value;
      this.index = index;
    }
  }
```