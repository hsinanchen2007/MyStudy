![image.png](https://pic.leetcode-cn.com/0c5c05be0c96234533f64aa92fee2750e6d6ff4b825acb4efe200fc2ffb666c4-image.png)

将二维数组转为一维，值用二维数组的[n][1]填充
[[1,4],[4,6]] 转为 a[] = [0,4,4,4,6,6,6]
遍历一维数组时，如果当前的数组索引不等于值，则为连续. a[4] != 4
[0,0] 需要特殊处理

```
public int[][] merge(int[][] intervals) {
        int[] a = new int[10000];
        int maxLength = 0;
        int zeroI = 0;
        for (int i = 0;i < intervals.length;i++) {
            for (int j = intervals[i][0];j <= intervals[i][1];j++) {
                //处理 0,0 的情况
                if (intervals[i][0] == 0 ) {
                    if ( intervals[i][1] == 0 && zeroI != 3) {
                        zeroI = 1;
                    } else {
                        zeroI = 3;
                    }
                }

                if (intervals[i][1] > a[j]) {
                    a[j] = intervals[i][1];
                }
                if (j > maxLength) {
                    maxLength = j;
                }
            }
        }
        List<int[]> list = new ArrayList<>();
        int t = 0;
        int l = 0;
        boolean c  = false;
        if (zeroI == 1) {
            list.add(new int[]{0,0});
        }
        while (t <= maxLength) {
            if (a[t] > 0 &&  !c) {
                l = t;
                c = true;
            }

            if (a[t]  == t && c) {
                list.add(new int[]{l,t});
                c = false;
            }
            t++;
        }
        return list.toArray(new int[list.size()][]);
    }
```
