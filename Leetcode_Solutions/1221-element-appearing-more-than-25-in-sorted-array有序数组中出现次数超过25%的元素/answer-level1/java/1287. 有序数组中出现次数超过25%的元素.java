# 方法一
计算每个数字出现的次数，然后找出出现次数最大的那个（出现次数最大的那个数，一定超过元素总数的25%）。
```
    public static int findSpecialInteger(int[] arr) {
        int max = arr[0], maxCount = 1, prevNum = arr[0], count = 1;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] == prevNum) {
                count++;
                if (count > maxCount) {
                    maxCount = count;
                    max = arr[i];
                }
            } else {
                prevNum = arr[i];
                count = 1;
            }
        }
        return max;
    }
```
# 方法二
因为最大的数出现的次数超过总元素的25%，所以当前元素i与总元素个数的25%一定相等。
注意：题意中只有一个正数出现次数超过总元素的25%
```
    public static int findSpecialInteger(int[] arr) {
        int j = arr.length / 4;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == arr[i+j]) return arr[i];
        }
        return -1;
    }
```

