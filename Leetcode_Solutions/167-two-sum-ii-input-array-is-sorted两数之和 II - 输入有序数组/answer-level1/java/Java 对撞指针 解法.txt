### 解题思路
使用对撞指针。
初始两指针分别在数组首尾，然后两位置上的数字相加；
若 和>目标数，则用小一点的数再试（右端指针前移一位）；
若 和<目标数，则用大一点的数再试（左端指针后移一位）；
直到找到两数满足要求。

### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int index1 = 0;
        int index2 = numbers.length - 1;
        while (index1 < index2) {
            while (index1 < index2 && (numbers[index1] + numbers[index2] > target)) {
                index2--;
            }
            while (index1 < index2 && (numbers[index1] + numbers[index2] < target)) {
                index1++;
            }
            if (numbers[index1] + numbers[index2] == target) {
                return new int[]{index1+1, index2+1};
            }
        }
        return null;
    }
}
```