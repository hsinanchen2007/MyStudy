### 解题思路
由于是有序数组，从左至右遍历，二分查找另一个值，如果找到就返回，没有找到就更新`right`，即遍历的范围，因为`right`为当前值相加后不超过`target`的位置，当前元素的后继值必然大于等于当前值，`right`后的值相加肯定大于`target`。

执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :43.4 MB, 在所有 Java 提交中击败了5.08%的用户

### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] res = new int[2];
        int index = 0, left, right = numbers.length - 1;
        // 遍历，界限为right
        for(; index < right; index++) {
            int temp = target - numbers[index];
            // 如果当前值和最大值之和小于target，跳过，继续下一轮循环
            if(numbers[index] + numbers[right] < target) {
                continue;
            }
            left = index + 1;
            // 查找，找到就返回，未找到就更新right
            while(left <= right) {
                int mid = (left + right) / 2;
                // 找到并返回
                if(numbers[mid] == temp) {
                    res[0] = index + 1;
                    res[1] = mid + 1;
                    return res;
                }
                // 二分
                if(numbers[mid] < temp) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        // 题目限定必然有一组解，此处不走
        return res;
    }
}
```