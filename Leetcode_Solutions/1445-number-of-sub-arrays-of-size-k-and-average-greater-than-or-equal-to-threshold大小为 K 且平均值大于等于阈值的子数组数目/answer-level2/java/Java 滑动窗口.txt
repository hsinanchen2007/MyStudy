定一个长度为k的窗口,遍历一整个数组然后求平均值大于阈值就让sum++.边界条件就是数组的长度减去去一个K长度**(arr.length - k)**
第一次参加比赛第一次写题解,求大佬不要嫌弃.
```
 public int numOfSubarrays(int[] arr, int k, int threshold) {
        int sum = 0;
        int flag = 0;
        //边界条件
        while (flag < arr.length - k) {
            //存放数组和
            int temp = 0;
            //从flag开始取一个k大小的窗口
            for (int i = flag; i <flag+ k; i++) {
                temp += arr[i];
            }
            if (temp / k >= threshold) {
                sum++;
            }
        }

        return sum;
    }
```
