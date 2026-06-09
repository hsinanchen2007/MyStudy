### 解题思路
思路如下。

### 代码

```java
class Solution {
    public int minArray(int[] numbers) {
        if (numbers == null || numbers.length == 0) {
            return -1;
        } // 参数合法性校验

        // 利用二分法寻找旋转点
        int left = 0, right = numbers.length - 1;
        while (left < right) { // 循环条件是left < right
            int mid = (left + right) / 2;
            // 如果中间值大于最右边的数据，则旋转点在右侧，更新left为mid+1
            if (numbers[mid] > numbers[right]) {
                left = mid + 1;
            }
            // 如果mid小于right的数据，则旋转点在左侧，更新right为mid
            else if (numbers[mid] < numbers[right]) {
                right = mid;
            }
            // 如果是相等则无法判断在哪个序列，此时需要不断移动right指针
            else {
                right--;
            }
        }
        return numbers[left];
    }
}
```