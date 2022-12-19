**算法思路：**
1. 先设置一个`指针i`进行遍历当前的元素
2. 然后进行`滑动窗口`，找出自指针i以后的元素中最大的那个，记录这个最大值的`索引`、`值`
3. 如果这个最大值比当前`指针i`指向的大，则进行替换，并返回结果（否则，返回原值）

```python []
class Solution(object):
    def maximumSwap(self, num):
        arr = map(int, list(str(num)))
        for i in range(len(arr)):
            sub = 0
            # 求出在当前i后面最大的数字
            for j in range(i+1, len(arr)):
                if arr[j] >= sub:
                    sub = arr[j]
                    max_index = j # 记录这个索引
            # 把当前的值和它后面的最大值(如果这个值比当前的还要大）进行交换；
            if arr[i] < sub:
                arr[i], arr[max_index] = arr[max_index], arr[i]
                return int(''.join(map(str, arr)))
        # 如果没有进行交换的话，说明本身就是最大值；
        return num
```
```Java []
class Solution {

    public int max_index;

    public int maximumSwap(int num) {
        String[] arr_str = String.valueOf(num).split("");
        int[] arr = new int[arr_str.length];
        for (int i = 0; i < arr_str.length; i++) {
            arr[i] = Integer.valueOf(arr_str[i]);
        }

        for (int i = 0; i < arr.length; i++) {
            int sub = 0;
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j] >= sub) {
                    sub = arr[j];
                    max_index = j;
                }
            }
            if (arr[max_index] > arr[i]) {
                int temp = arr[i];
                arr[i] = arr[max_index];
                arr[max_index] = temp;
                int sums = 0;
                for (int k = 0; k < arr.length; k++) {
                    sums = sums * 10 + arr[k];
                }
                return sums;
            }
        }
        return num;
    }
}
```


