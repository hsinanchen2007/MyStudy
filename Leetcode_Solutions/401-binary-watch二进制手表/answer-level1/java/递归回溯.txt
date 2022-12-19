### 解题思路
此处撰写解题思路
先将排列组合算好，再计算时间是否合理。
递归+回溯
### 代码

```java
class Solution {
  public List<String> readBinaryWatch(int num) {
        List<int[]> resTmp = new ArrayList<>();

        int[] tmp = new int[10];
        initTime(num, tmp, resTmp, 0);

        List<String> resStrs = new ArrayList<>();
        for (int[] oneTime : resTmp) {

            int hour = oneTime[0] * 8 + oneTime[1] * 4 + oneTime[2] * 2 + oneTime[3];
            if (hour > 11) {
                continue;
            }
            int minitue =
                oneTime[4] * 32 + oneTime[5] * 16 + oneTime[6] * 8 + oneTime[7] * 4 + oneTime[8] * 2 + oneTime[9];
            if (minitue > 59) {
                continue;
            }

            String minStr = minitue >= 10 ? "" + minitue : "0" + minitue;

            resStrs.add(""+hour+":"+minStr);
        }

        return resStrs;

    }

    private void initTime(int num, int[] tmp, List<int[]> resTmp, int idx) {

        if (10 - idx < num) {
            return;
        }
        if (num == 0) {
            resTmp.add(tmp);
            return;
        }

        int[] newE = Arrays.copyOf(tmp, tmp.length);
        newE[idx] = 0;

        initTime(num, newE, resTmp, idx + 1);

        tmp[idx] = 1;
        initTime(num - 1, tmp, resTmp, idx + 1);
    }
}
```