- 由题意可知，当前数组中最大的元素一定是上一轮被替换的元素，且该元素的值一定是上一轮所有元素之和
- 根据这一观察，可以由数组在第n+1次赋值后的状态反推第n次赋值后的状态
- 由于我们要找当前最大的元素，且经过逆推之后，最大的元素可能发生变化，因此考虑使用优先队列来进行最大元素的维护和获取
- 由于引入了新的用例，原有的每次计算后入队的做法已不适用，本次将方法修正为将最大的元素一直减小，直到小于次小的元素才会再次入队，减少sift操作开销

```
class Solution {
    private PriorityQueue<Long> q;
    private long sum = 0;

    public boolean isPossible(int[] target) {
        if (target.length == 1 && target[0] == 1) return true;
        if (target.length == 1) return false;
        initialize(target);
        while (!q.isEmpty()) {
            long previousSum = q.poll();
            long othersSum = sum - previousSum;
            long previousVal;
            long base = (!q.isEmpty() ? q.peek() : 1);
            do {
                previousVal = previousSum - othersSum;
                previousSum = previousVal;
            } while (previousVal > base);
            
            if (!q.isEmpty()) {
                if (previousVal == base || previousVal < 1) return false;
                sum = previousVal + othersSum;
                if (previousVal == 1) continue;
                q.offer(previousVal);
            } else {
                return previousVal == base;
            }
        }
        return true;
    }

    private void initialize(int[] target) {
        q = new PriorityQueue<>(target.length, Comparator.reverseOrder());
        for (long value : target) {
            sum += value;
            if (value > 1)
                q.offer(value);
        }
    }
}
```
