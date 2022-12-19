### 解题思路
1.对撞指针，因为所给数组有序，index1必须小于index2，O(n)。
2.HashSet, 用target减去遍历到的数，用得到的差再去HashSet中寻找，如果找到就返回坐标，没找到就把遍历到的数添加到HashSet，也是O(n)吧。

### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int l = 0;
        int r = numbers.length - 1;
        while (l < r) {
            if (numbers[l] + numbers[r] > target) r--;
            else if (numbers[l] + numbers[r] < target) l++;
            else
                return new int[]{l+1, r+1};
        }
        return numbers;
    }
}
```