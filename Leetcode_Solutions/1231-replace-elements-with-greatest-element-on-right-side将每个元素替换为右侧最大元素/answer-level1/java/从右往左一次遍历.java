![结果.png](https://pic.leetcode-cn.com/1b378873c78840b5a07cf5b2ef3170a1d0f0aa3eefc0509bb7a8e17de9dd3b83-%E7%BB%93%E6%9E%9C.png)

从右往左遍历，先记录右边最大值 rightMax 为最后一个值，向左每次更新 rightMax，使用变量 t 先记住当前 arr[i] 就可以了。
```
class Solution {
    public int[] replaceElements(int[] arr) {
        int rightMax = arr[arr.length - 1];
        arr[arr.length - 1] = -1;
        for (int i = arr.length - 2; i >= 0; i--) {
            int t = arr[i];
            arr[i] = rightMax;
            if (t > rightMax)
                rightMax = t;
        }
        return arr;
    }
}
```

