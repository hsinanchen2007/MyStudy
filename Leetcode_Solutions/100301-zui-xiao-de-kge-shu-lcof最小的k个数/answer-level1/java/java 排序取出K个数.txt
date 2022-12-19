### 解题思路
java 排序取出K个数

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {

        if(arr ==null ||arr.length ==0){
            return new int[0];
        }

        int len = arr.length;
        if(k>=len){
            return arr;
        }

        Arrays.sort(arr);
        int res[] = new int[k];
        
        res = Arrays.copyOf(arr,k);
        return res;
    }
}
```