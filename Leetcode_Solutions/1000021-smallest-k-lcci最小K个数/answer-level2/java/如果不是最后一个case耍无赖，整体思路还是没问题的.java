### 解题思路
排序+返回前k个
使用堆排序其实是不错的解法
但是无奈最后一个case耍流氓
力dog～你能找一个手写 N枢轴量 排序的人来？

### 代码

```java
class Solution {
    public int[] smallestK(int[] arr, int k) {
        // for(int i=0;i<k;i++){
            // 堆排序最后一个测试case无法通过
            // 因为时间太长
            // sort0(arr, i);
            // 经过实地测试
            // 使用JDK自带的双枢轴量快排，最后一个case只需要22毫秒
            // 而使用自己写的堆排序最后一个case要5.9秒差距250倍
            // 但是这个题目的操蛋之处是你不可能自己写出一个双枢轴量排序
            // 而JDK更牛逼的是随着数据量的增大，可以是N枢轴量排序
            // 这最后一个case堪称不要脸的典范
            // 如果不是复制黏贴请问谁能手写N枢轴排序？
            // 所以我只能耍流氓了
            // [手动狗头]
        // }
        Arrays.sort(arr);
        return Arrays.copyOfRange(arr, 0 , k);
    }

    public void sort0(int[] arr, int offset) {
        // 从offset开始计算为0
        // 使用相同的空间
        for (int i = offset; i < arr.length; i++) {
            int j = i-offset;
            while (j > 0) {
                int parent;
                int parentIndex;
                boolean even = j % 2 == 0;
                if (even) {
                    parentIndex = (j - 2) / 2;
                } else {
                    parentIndex = (j - 1) / 2;
                }
                if (arr[j+offset] < arr[parentIndex+offset]) {
                    parent = arr[parentIndex+offset];
                    arr[parentIndex+offset] = arr[j+offset];
                    arr[j+offset] = parent;
                    j = parentIndex;
                    continue;
                } else {
                    break;
                }
            }
        }
    }
}
```