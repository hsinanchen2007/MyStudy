### 解题思路


### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        Arrays.sort(arr);
        int []nums = new int[k];
        for(int i=0;i<k;i++){
            nums[i]= arr[i];
        }
        return nums;
    }
}
```