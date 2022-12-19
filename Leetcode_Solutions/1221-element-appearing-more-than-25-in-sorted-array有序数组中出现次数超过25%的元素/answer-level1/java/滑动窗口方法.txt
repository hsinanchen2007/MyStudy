使用滑动窗口方法, 窗口大小为arr.length/4, 判断该窗口的首数字与尾数字是否相等
代码如下: 
```
    public int findSpecialInteger(int[] arr) {
        int j = arr.length / 4;
        for (int i = 0; i < arr.length - j; i++) {
            if (arr[i] == arr[i + j]) {
                return arr[i];
            }
        }
        return -1;
    }
```