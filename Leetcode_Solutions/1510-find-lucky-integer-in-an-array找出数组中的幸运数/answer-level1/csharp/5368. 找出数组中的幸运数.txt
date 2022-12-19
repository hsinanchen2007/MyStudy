提示：

1 <= arr.length <= 500
1 <= arr[i] <= 500

```
代码块
public class Solution {
    public int FindLucky(int[] arr) {
            int[] count = new int[501];
            for (int i = 0; i < arr.Length; i++) count[arr[i]]++;
            for (int i = arr.Length; i > 0; i--){
                if (count[i] == i)return i;
            }
            return -1;
    }
}

```

