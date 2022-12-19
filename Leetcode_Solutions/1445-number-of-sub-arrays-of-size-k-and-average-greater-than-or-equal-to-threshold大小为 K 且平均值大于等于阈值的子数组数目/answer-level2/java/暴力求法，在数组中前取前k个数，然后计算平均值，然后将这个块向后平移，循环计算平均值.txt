### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        int num = k;
        int result = 0;
        int begin = 0;
        while(k <= arr.length){
            int sum = 0;
            for(int i= begin; i<k;i++){
                sum = sum + arr[i];
            }
            if(sum/num >= threshold){
                result++;
            }
            begin++;
            k++;
        }
        return result;
    }
}
```