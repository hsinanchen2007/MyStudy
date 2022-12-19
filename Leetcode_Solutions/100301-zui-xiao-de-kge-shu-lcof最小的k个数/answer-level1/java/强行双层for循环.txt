### 解题思路
强行双层循环来解题了。。。时间复杂度达到了O(k*n)

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        if (k == 0 || arr.length == 0) return new int[]{};

        int[] res = new int[k];

        int min = -1;

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < arr.length; j++) {

                if (arr[j] < 0) continue;

                if (min == -1 || arr[min] > arr[j]) {
                    min = j;
                }
            }
            res[i] = arr[min];
            arr[min] = -1;
            min = -1;
        }

        return res;
    }
}
```