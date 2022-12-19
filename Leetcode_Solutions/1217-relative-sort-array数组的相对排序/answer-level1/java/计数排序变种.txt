这个问题实际上就是计数排序的变种，不同点在于：

1. 排序方式：计数排序按**非降序**排序，本题按参数`arr2`的元素排序
2. `arr2`中没有出现的元素需要额外处理

复杂度分析：

* 时间复杂度：O(n);
* 空间复杂度：Ɵ(max(n) - min(n) + 1)

执行结果：
> 执行用时 :1 ms, 在所有 Java 提交中击败了99.86%的用户
> 内存消耗 :35.7 MB, 在所有 Java 提交中击败了100.00%的用户

相关代码：

```
public int[] relativeSortArrayV2(int[] arr1, int[] arr2) {
    // 确定统计的范围，减少内存占用
    int min = arr1[0], max = arr1[0];
    int i = 1;
    for(; i < arr1.length; i++) {
        if(arr1[i] < min) {
            min = arr1[i];
        }
        if(arr1[i] > max) {
            max = arr1[i];
        }
    }
    int[] tmp = new int[max - min + 1];
    for(i = 0; i < arr1.length; i++) {
        tmp[arr1[i] - min]++; // 统计arr1中各元素的数量
    }
    int[] res = new int[arr1.length];
    int index = 0, count = 0;
    for(i = 0; i < arr2.length; i++) { // 首次遍历处理出现在arr2的元素
        count = tmp[arr2[i] - min];
        while(count-- > 0) {
            res[index++] = arr2[i];
        }
        tmp[arr2[i] - min] = 0;
    }
    for(i = 0; i < tmp.length; i++) { // 第二次遍历处理arr2中没有的元素
        count = tmp[i];
        while(count-- > 0) {
            res[index++] = i + min;
        }
    }
    return res;
}
```