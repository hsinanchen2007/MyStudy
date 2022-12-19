# 解题思路
1. 统计各数字出现的次数。
2. 判断数字出现的次数是否重复。
# 代码
```
    public boolean uniqueOccurrences(int[] arr) {
        //统计各数字出现的次数
        int[] counts = new int[2001];
        for (int num : arr) {
            counts[num + 1000]++;
        }

        //判断数字出现的次数是否重复
        boolean[] countExist = new boolean[1001];
        for (int count : counts) {
            if (count == 0) {
                continue;
            }
            if (countExist[count]) {
                return false;
            } else {
                countExist[count] = true;
            }
        }
        return true;
    }
```
