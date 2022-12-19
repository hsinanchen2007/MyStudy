实现思路：偶数放数组最前面，奇数放数组最后面
 1. 记录偶数,奇数每次加入数组的下标。
 2. 偶数插入数组下标为：下标+1,奇数插入数组下标为：数组长度减去记录下标

```
    public int[] sortArrayByParity(int[] A) {
        int aLength = A.length;
        int[] nums = new int[aLength];
        int evenIndex = 0;
        int oddNumIndex = 0;
        for (int i = 0; i < aLength; i++) {
            if ((A[i] % 2) == 0) {
                nums[evenIndex] = A[i];
                evenIndex += 1;
            } else {
                //因为aLength是A.length,所以需要多-1。这样写好理解
                nums[aLength - oddNumIndex - 1] = A[i];
                oddNumIndex += 1;
            }
        }
        return nums;
    }
```

![100.png](https://pic.leetcode-cn.com/bb73954cba8b2d08cf8c34d7f0c3857ec3cf0fc4152121f3f1cdc4dc777a2a87-100.png)

![新垣结衣.gif](https://pic.leetcode-cn.com/c348ab436965d456bcaf26fa39f2349a88c5e453259d2276182dae273841e76c-%E6%96%B0%E5%9E%A3%E7%BB%93%E8%A1%A3.gif)
