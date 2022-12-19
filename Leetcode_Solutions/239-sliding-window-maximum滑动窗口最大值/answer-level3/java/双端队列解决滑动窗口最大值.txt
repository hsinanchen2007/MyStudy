算法
 
 算法非常直截了当：
 
 处理前 k 个元素，初始化双向队列。
 
 遍历整个数组。在每一步 :
 
 清理双向队列 :
 
   - 只保留当前滑动窗口中有的元素的索引。
 
   - 移除小于等于当前元素的所有元素，它们不可能是最大的。

 将当前元素添加到双向队列中。

加数逻辑：
双端队列有个特点：从头到尾数字是严格从大到小的。
减数逻辑：
L从左往右移动，如果过期从头部弹出数字

```
public static int[] getMaxWindow(int[] arr, int w) {
        if(arr == null || w < 1 || arr.length <w){
            return new int[]{};
        }
        LinkedList<Integer> qmax = new LinkedList<>();
        int[] res = new int[arr.length - w + 1];
        int index = 0;
        for (int i = 0;i < arr.length;i++) {
            while (!qmax.isEmpty() && arr[qmax.peekLast()] <= arr[i]) {
                qmax.pollLast();
            }
            qmax.addLast(i);
            if (qmax.peekFirst() == i - w) {
                qmax.pollFirst();
            }

            if (i >= w - 1) {
                res[index++] = arr[qmax.peekFirst()];
            }
        }
        return res;
    }
```


