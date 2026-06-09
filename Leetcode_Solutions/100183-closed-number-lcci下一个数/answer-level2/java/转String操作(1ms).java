# PS:
想不到位操作就只能转成String了(摊手)

```java
class Solution {
    public int[] findClosedNumbers(int num) {
        String str_num = Integer.toBinaryString(num);
        int len = str_num.length(), idx_1 = -1, last1_idx = -1;
        int[] res = new int[]{-1, -1};
        StringBuilder sb = new StringBuilder(str_num);
        boolean found = false;
        int count = 1;
        //从右往左找第1个"01"
        for (int i = len - 1; i > -1; --i) {
            if (str_num.charAt(i) == '1') {
                last1_idx = i;
                if (i > 0 && str_num.charAt(i - 1) == '0') {
                    idx_1 = i;
                    found = true;
                    break;
                }
            } else
                ++count;
        }
        if (found) {
            sb.setCharAt(idx_1 - 1, '1');
            for (int i = 0; i < count; ++i)
                sb.setCharAt(idx_1 + i, '0');
            idx_1 += count;
            for (; idx_1 < len; ++idx_1)
                sb.setCharAt(idx_1, '1');
            res[0] = Integer.valueOf(sb.toString(), 2);
        } else {
            if (len < 31) {
                sb.setCharAt(last1_idx, '0');
                sb.insert(0, '1');
                res[0] = Integer.valueOf(sb.toString(), 2);
            }
        }
        sb = new StringBuilder(str_num);
        found = false;
        count = 0;
        //从右往左找第1个"10"
        for (int i = len - 1; i > -1; --i) {
            if (str_num.charAt(i) == '1') {
                ++count;
                if (i + 1 < len && str_num.charAt(i + 1) == '0') {
                    idx_1 = i;
                    found = true;
                    break;
                }
            }
        }
        if (found) {
            sb.setCharAt(idx_1, '0');
            for (int i = 1; i <= count; ++i)
                sb.setCharAt(idx_1 + i, '1');
            idx_1 += count + 1;
            for (; idx_1 < len; ++idx_1)
                sb.setCharAt(idx_1, '0');
            res[1] = Integer.valueOf(sb.toString(), 2);
        }

        return res;
    }
}
```
