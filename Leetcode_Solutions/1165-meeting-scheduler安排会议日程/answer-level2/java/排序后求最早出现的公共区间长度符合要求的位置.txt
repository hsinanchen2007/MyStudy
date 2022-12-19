先对两个二维数组按照起始时间进行排序，首先双指针指向起始位置，然后移动找到有公共区间的位置。
由len=min(c,d)-max(a,b)，求出公共区间长度，如果大于duration，则返回正确的区间。
否则，end较小的一者的指针向后移动。

```
class Solution {
    public List<Integer> minAvailableDuration(int[][] slots1, int[][] slots2, int duration) {
        List<Integer> list = new ArrayList<>();
        Comparator cmp = new MyComparator();
        Arrays.sort(slots1, cmp);
        Arrays.sort(slots2, cmp);
        for (int i = 0, j = 0; i < slots1.length && j < slots2.length; ) {
            while (slots1[i][0] > slots2[j][1]) j++;
            while (slots1[i][1] < slots2[j][0]) i++;

            int right = Math.min(slots1[i][1], slots2[j][1]);
            int left = Math.max(slots1[i][0], slots2[j][0]);
            int len = right - left;
            if (len >= duration) {
                list.add(left);
                list.add(left + duration);
                return list;
            } else {
                if (slots2[j][1] > slots1[i][1]) i++;
                else if (slots2[j][1] < slots1[i][1]) j++;
            }
        }
        return list;
    }
}

class MyComparator implements Comparator<int[]> {

    @Override
    public int compare(int[] o1, int[] o2) {
        if (o1[0] == o2[0])
            return o1[1] - o2[1];
        return o1[0] - o2[0];
    }
}
```
