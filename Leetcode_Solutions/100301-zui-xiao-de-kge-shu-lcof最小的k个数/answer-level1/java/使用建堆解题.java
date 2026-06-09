### 解题思路
堆排序的时间复杂度为 n * logN 这里要查询K下小数；所以时间复杂度为： k * logN ; 

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        if (arr == null || arr.length < 2 ){
            return arr;
        }
        int len = arr.length / 2;

        for (int i = len ; i >= 0 ; i-- ){
            heapAdjust(arr,arr.length,i);
        }
        for(int i = arr.length -1 ; i >= arr.length - k; i-- ){
            swap(arr,0,i);
            heapAdjust(arr,i,0);
        }
        int[] res = new int[k];
        int idx = 0 ;
        for (int i = arr.length - 1 ; i >= arr.length - k ; i-- ){
            res[idx++] = arr[i];
        }
        return res;
    }
    public static void swap(int arr[] ,int left,int right){
        if ( left == right){
            return ;
        }
        arr[left] = arr[left] + arr[right];
        arr[right] = arr[left] - arr[right];
        arr[left] = arr[left] - arr[right];
    }

    public static void heapAdjust(int arr[], int length, int idx){
        int tmp = arr[idx];
        for (int i = 2 * idx + 1; i < length; i = 2 * i + 1) {
            if (i + 1 < length) {
                if (arr[i] > arr[i + 1]) {
                    i = i + 1;
                }
            }
            if (arr[i] < tmp) {
                arr[idx] = arr[i];
                idx = i;

            }
        }
        arr[idx] = tmp;
    }
}
```