思路：由于要达到局部有序且整体有序的效果，说明**下一分组的最小值要大于或等于当前分组的最大值**。
- 令max[]数组保存从第一个数开始到当前数字之间的最大值。
    如arr=[2,1,3,4,4]， 则max=[2,2,3,4,4];
- 从后往前遍历，利用cmin记录最小值，不断与当前的最大值进行比较
```
    public int maxChunksToSorted(int[] arr) {
        int[] max = new int[arr.length];
        max[0] = arr[0];
        for(int i=1; i<arr.length; i++)
            max[i] = Math.max(arr[i], max[i-1]);
        int cmin = Integer.MAX_VALUE, re=0;
        for (int i = arr.length-1; i >=0; i--) {
            // 确切地说，cmin记录的是arr[i+1]到最后一个数之间的最小值
            // 如果cmin >= max[i], 则i这里就是一个分割点
            if(cmin >= max[i])
                re++;
            cmin = Math.min(cmin,arr[i]);
        }
        return re;
    }
```