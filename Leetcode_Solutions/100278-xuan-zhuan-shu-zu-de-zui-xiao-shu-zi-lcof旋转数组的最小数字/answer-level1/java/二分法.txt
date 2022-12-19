### 代码

```java
class Solution {
    public int minArray(int[] numbers) {
        if(numbers == null || numbers.length == 0) return 0;
        int left = 0;
        int right = numbers.length - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (numbers[mid] > numbers[right]) {//此时mid 以及 mid 的左边的数一定不是最小数字
                left = mid + 1;
            } else if (numbers[mid] == numbers[right]) {//无法确认最小数字在那一边
                // 只能把 right 排除掉，下一轮搜索区间是 [left, right - 1]
                right = right - 1;
            } else {// 此时numbers[mid] < numbers[right]，mid 的右边一定不是最小数字，但mid 有可能是，故right=mid
                right = mid;
            }
        }
        // 这个时候left=right,下标是left或right都一样
        return numbers[right];
    }
}
```