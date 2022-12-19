### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minArray(int[] numbers) {
        int l = 0, r = numbers.length - 1;
        int mid = l;
        while (numbers[l] >= numbers[r]) {
            if (r - l == 1) {
                mid = r;
                break;
            }
            mid = (l + r) / 2;
            if (numbers[l] == numbers[r] && numbers[l] == numbers[mid])
                return minInOrder(numbers, l, r);
            if (numbers[mid] >= numbers[l]) {
                l = mid;
            } else if (numbers[mid] <= numbers[r]) {
                r = mid;
            }
        }
        return numbers[mid];
    }

    private int minInOrder(int[] number, int l, int r){
        int result = number[l];
        for (int i = l + 1; i < r; i++) {
            if (result > number[i]){
                result = number[i];
            }
        }
        return result;
    }
}
```