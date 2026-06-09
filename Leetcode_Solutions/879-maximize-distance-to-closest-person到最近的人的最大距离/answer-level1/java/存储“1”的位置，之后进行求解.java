首先建立一个 list 存储 seats数组 中 “1” 的位置，接下来设置一个变量 max 来记录两个 1 中最远的距离。
接下来只需判断 `max / 2`，`seats.length - (int)num[num.length - 1] - 1`(末尾到最近一个 1 的距离)，`(int)num[0]`(第一个 1 到seats数组首尾的距离) 中的最大值即可。

```
class Solution {
    public int maxDistToClosest(int[] seats) {
        List list = new ArrayList<>();
        for(int i = 0;i < seats.length;i++){
            if(seats[i] == 1)
                list.add(i);
        }
        Object[] num = list.toArray();
        int max = 0;
        for(int i = 0;i < num.length - 1;i++){
            int check = (int)num[i + 1] - (int)num[i];
            if(max < check)
                max = check;
        }
        int key = Math.max(max / 2,(int)num[0]);
        return Math.max(key,seats.length - (int)num[num.length - 1] - 1);
    }
}
```

