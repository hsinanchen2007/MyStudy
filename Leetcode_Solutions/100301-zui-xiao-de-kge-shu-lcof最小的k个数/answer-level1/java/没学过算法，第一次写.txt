### 解题思路
先用冒泡排序，在找出前 k 个最小数组。

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        int[] arr2 = new int[k];
        for(int i = 0;i < arr.length;i++){
            for (int j = 0; j < arr.length - i - 1; j++){
                if (arr[j] > arr[j + 1]) {
                    arr[j] ^= arr[j + 1];
                    arr[j + 1] ^= arr[j];
                    arr[j] ^= arr[j + 1];
                }
            }
        }
        for(int i = 0;i < k;i++){
            arr2[i] = arr[i];
        }
        return arr2;
    }
}
```