### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
       for(int i =0;i<arr.length;i++){
           for(int j = 0;j<arr.length-i-1;j++){
               if(arr[j]>arr[j+1]){
                   int temp = 0;
                   temp = arr[j];
                   arr[j] = arr[j+1];
                   arr[j+1] = temp;
               }
           }
       }
       int[] arrs = new int[k];
       int j = 0;
       for(int i = 0;i<k;i++){
           arrs[j] = arr[i];
           j++;
       }
       return arrs;
    }
}
```