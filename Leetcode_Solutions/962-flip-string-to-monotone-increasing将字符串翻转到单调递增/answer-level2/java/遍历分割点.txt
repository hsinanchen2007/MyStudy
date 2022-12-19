反向遍历一次存储需要翻转的0，正向遍历一次获得需要翻转的1，各切割点相加取最小值
```
class Solution {
    public int minFlipsMonoIncr(String S) {
        char[] str = S.toCharArray();
        int length = S.length();
        int before = 0;
        int after = 0;
        int sum = 20000;
        int[] afters = new int[length + 1];
        for (int i = 0; i < length + 1; i++) {
            if (i != 0 && str[length - i] == '0') {
                after ++;
            }
            afters[length - i] = after;
        }
        for (int i = 0; i < length + 1; i++) {
            if (i != 0 && str[i - 1] == '1') {
                before ++;
            }
            if (sum > before + afters[i]) {
                sum = before + afters[i];
            }
        }
        return sum;
    }
}
```