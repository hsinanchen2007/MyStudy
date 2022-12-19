### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        if( k ==0 || arr.length == 0){
            return new int[0];
        }

        return Arrays.stream(arr).sorted().limit(k).toArray();


    }

    
}
```