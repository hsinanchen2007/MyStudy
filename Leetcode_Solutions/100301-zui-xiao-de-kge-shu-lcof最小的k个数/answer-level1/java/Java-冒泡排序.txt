### 解题思路
用冒泡排序将arr变为有序数组，取最前面k位。

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        for(int i = 0; i < arr.length; i++) {
            for(int j = 0; j < arr.length-i-1; j++) {
                if(arr[j]>arr[j+1]){
                    int x = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = x;
                }
            }
        }
        int[] result = new int[k];
        for(int i = 0; i < result.length; i++) {
            result[i] = arr[i];
        }
        return result;
    }
}
```