### 代码

```java
class Solution {
    public int missingNumber(int[] arr) {
        int length = arr.length;
        int diff = (arr[length-1] - arr[0])/length;
        int i = 0;
        for(; i < length - 1; i++){
            if(arr[i+1] - arr[i] != diff){
                break;
            }
        }
        return arr[i] + diff;

        
    }
}
```