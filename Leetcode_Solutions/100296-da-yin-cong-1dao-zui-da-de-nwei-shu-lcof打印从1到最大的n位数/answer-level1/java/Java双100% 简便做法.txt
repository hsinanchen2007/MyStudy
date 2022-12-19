
![Snipaste_2020-03-23_11-08-03.png](https://pic.leetcode-cn.com/6f5ffb0fab35fd28b50af61700be556fc862b4bf2ee5c80274f1dfc2bbf69552-Snipaste_2020-03-23_11-08-03.png)

```
class Solution {
    public int[] printNumbers(int n) {
        int begin = 1;
        int end = (int)Math.pow(10, n);
        int[] arr = new int[end - begin];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = begin;
            begin++;

        }
        return arr;
    }
}
```

```


