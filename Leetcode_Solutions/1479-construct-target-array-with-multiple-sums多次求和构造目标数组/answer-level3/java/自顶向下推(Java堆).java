# 思路

这个题标识hard，其实没那么恐怖，自底向上有很多选择，枚举不现实。但是换个思路，自顶向下就是唯一选择了，只能是最大值是上一轮的和，因此直接一步步还原就行，用减法会超时，取余就可以了，其实算是一道`medium`吧。

# 代码
```
class Solution {
    
  public boolean isPossible(int[] target) {
    long sum = 0;
    PriorityQueue<Integer> queue = new PriorityQueue<>(Collections.reverseOrder());
    for (int num : target) {
      sum += num;
      queue.add(num);
    }
    while (true) {
      int max = queue.poll();
      if (max == 1) {
        return true;
      }
      int pre = max;
      if(max <= sum - pre){
        return false;
      }
      max %= sum - pre;
      sum += max - pre;
      queue.add(max);
    }
  }
}
```