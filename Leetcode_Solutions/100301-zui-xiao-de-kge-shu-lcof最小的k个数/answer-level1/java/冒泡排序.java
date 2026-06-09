### 解题思路
此处撰写解题思路
使用冒泡排序

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        for(int i = 0;i<arr.length;i++){
            for(int j = 0;j<arr.length-i-1;j++){
                if(arr[j+1]<arr[j]){
                    int temp = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        int[] result = new int[k];
        if(k<=arr.length){
            for(int i = 0;i<k;i++){
                result[i]=arr[i];
            }
        }
        return result;
    }
}
```