### 解题思路
方法一：暴力求解的方法，这里可以使用两个指针，指针i用于遍历，指针j用于在i的基础上对值进行累加。共有三种情况：
    1，当sum < target 时，指针j需要往前走，继续累加。此时i的值不变。
    2，当sum >target 时，这时需要sum - i 来是sum减小，并且指针i需要往前走，因为我们已经知道了如果j继续往前走的话sum肯定更大。
    3，当sum = target 时，这时即找到所需要的值的范围了，赋值下来。并且让sum - i ,i 继续往前走，遍历下一种可能的情况。
  注意这里循环的范围只要在：<=tareget/2；

执行结果：用时5ms，打败67.58%java用户。
        内存消耗37.4MB，打败100%用户。

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int[]> result = new ArrayList<>();
        int i = 1, j = 1;
        int sum = 0;
        while (i <= target / 2) {
            if (sum > target) {
                sum -= i++;
            } else if (sum < target) {
                sum += j++;
            } else {
                int[] res  = new int[j - i];
                for (int k = i ; k < j ; k++) {
                    res[k - i] = k;
                }
                result.add(res);
                sum -= i++;
            }
        }
        return result.toArray(new int[result.size()][]);

    }
}
```