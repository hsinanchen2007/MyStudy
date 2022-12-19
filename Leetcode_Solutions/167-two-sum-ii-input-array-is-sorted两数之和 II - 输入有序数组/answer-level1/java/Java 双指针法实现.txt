### 解题思路
用双指针法
当target减去头指针的值小于尾指针的值的时候，尾指针前移一格。
当target减去头指针的值不小于尾指针的值的时候，判断是否相等，如果相等则返回。
不相等的话，头指针后移一格。
例：
numbers={1, 3, 4, 7, 9} target=5
1. 初始化头位于0，尾位于length-1即4
2. target-numbers[head]<numbers[tail]即5-1<9
3. 因为数组单调，所以想要寻找到合适的tail值只需要将tail前移
4. 当target-numbers[head]>=numbers[tail]时，判断是否相等。如果相等，则返回结果。如果不相等则增加head，然后继续循环和判断，直至找到结果或者遍历结束丢出exception。


### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {

        int tail = numbers.length - 1;
        for (int i = 0; i < numbers.length && i < tail; i++) {
            while (target - numbers[i] < numbers[tail]) {
                tail--;
            }
            if (target - numbers[i] == numbers[tail]) {
                return new int[] {i + 1, tail + 1};
            }
        }
        throw new IllegalArgumentException("No Numbers Sum to Target!");
    }
}
```