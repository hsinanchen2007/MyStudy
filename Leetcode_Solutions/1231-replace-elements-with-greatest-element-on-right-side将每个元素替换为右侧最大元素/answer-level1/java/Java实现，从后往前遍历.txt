比较简单，直接看代码吧。
```
import java.lang.*;
class Solution {
    public int[] replaceElements(int[] arr) {
        int[] res = new int[arr.length];
        int max = arr[arr.length - 1];
        res[arr.length - 1] = -1;
        for(int i = arr.length - 2;i>= 0;i--){
            res[i] = max;
            max = Math.max(max,arr[i]);
        }
        return res;
    }
}
```
