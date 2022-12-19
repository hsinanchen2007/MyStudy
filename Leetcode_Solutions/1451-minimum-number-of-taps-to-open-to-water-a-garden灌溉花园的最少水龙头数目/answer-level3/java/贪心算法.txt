
把问题转化成如下形式：花园的长度为`n`，即共有`n`段区间，编号从`0`到`n - 1`。求可以灌溉所有区间的最少水龙头数目。对于每个水龙头，求得该水龙头可以灌溉的区间范围。
使用贪心算法。从区间`0`到区间`n - 1`遍历所有区间，对于每个区间，如果该区间已经被一个开启的水龙头灌溉则跳过，如果该区间尚未被灌溉，则找到一个水龙头，使得该区间可以被该水龙头覆盖，且开启该水龙头可以使被灌溉的区间的增加量最大。注意是增加量最大，即新开启的水龙头灌溉的范围内可能有部分区间已经被之前开启的水龙头灌溉，则这些已经被灌溉的区间不属于被新开的水龙头灌溉的区间，只有原来没有被灌溉，开启新水龙头后被灌溉的区间才算入增加量。
从花园的左端开始的理由是，区间`0`必须被灌溉，因此必须找到一个水龙头可以灌溉区间`0`。如果有多个水龙头都可以灌溉区间`0`，则显然灌溉范围最大的水龙头是更优的选择。
当已经有水龙头开启灌溉了部分区间，则在选择其余水龙头时应该考虑尚未被灌溉的区间，因此考虑增加量。
```
class Solution {
    public int minTaps(int n, int[] ranges) {
        int[][] minMaxArray = new int[n + 1][2];
        for (int i = 0; i <= n; i++) {
            int range = ranges[i];
            int min = Math.max(i - range, 0);
            int max = Math.min(i + range - 1, n - 1);
            minMaxArray[i][0] = min;
            minMaxArray[i][1] = max;
        }
        boolean[] covered = new boolean[n];
        int coverCount = 0;
        int openCount = 0;
        boolean[] used = new boolean[n + 1];
        boolean flag = true;
        while (flag) {
            flag = false;
            for (int i = 0; i < n; i++) {
                if (covered[i])
                    continue;
                int maxLengthIndex = -1;
                int maxLength = 0;
                for (int j = 0; j <= n; j++) {
                    if (used[j])
                        continue;
                    int[] array = minMaxArray[j];
                    int min = array[0], max = array[1];
                    if (min <= i && max >= i) {
                        int length = 0;
                        for (int k = min; k <= max; k++) {
                            if (!covered[k])
                                length++;
                        }
                        if (length > maxLength) {
                            maxLengthIndex = j;
                            maxLength = length;
                        }
                    }
                }
                if (maxLengthIndex >= 0) {
                    used[maxLengthIndex] = true;
                    int min = minMaxArray[maxLengthIndex][0], max = minMaxArray[maxLengthIndex][1];
                    for (int j = min; j <= max; j++) {
                    	if (!covered[j]) {
                    	    covered[j] = true;
                            coverCount++;
                    	}
                    }
                    flag = true;
                    openCount++;
                }
            }
        }
        return coverCount == n ? openCount : -1;
    }
}
```
