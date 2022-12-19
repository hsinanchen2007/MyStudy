### 解题思路
1.第一遍遍历找到最大index.
2.如果最大index是第一个或最后一个数直接返回false.
3.从0-index如果不是严格递增返回false.
4.从index-尾如果不是严格递减返回false.
5.最后即是true.

### 代码

```java
class Solution {
    public boolean validMountainArray(int[] A) {
        if (A.length < 3) {
            return false;
        }
        int max = 0;
        int index = 0;

        for (int i = 0; i < A.length; i++) {
            if (A[i] > max) {
                max = A[i];
                index = i;
            }
        }

        if (index == 0 || index == A.length - 1) {
            return false;
        }
        for (int i = 0; i < index; i++) {
            if (A[i] >= A[i + 1]) {
                return false;
            }
        }

        for (int i = index; i < A.length - 1; i++) {
            if (A[i] <= A[i + 1]) {
                return false;
            }
        }
        return true;
    }
}
```