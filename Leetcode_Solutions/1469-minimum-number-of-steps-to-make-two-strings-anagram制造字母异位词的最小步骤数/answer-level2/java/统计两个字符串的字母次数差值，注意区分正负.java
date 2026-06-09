遍历字符串`s`和`t`，记录每个字母在两个字符串中的次数的差值，用正数表示`s`中的次数大于`t`中的次数，用负数表示`s`中的次数小于`t`中的次数。由于`s`和`t`的长度相同，所有字母的次数差值的和为0，即所有正差值的和等于所有负差值的和的绝对值。将负差值的字母替换成正差值的字母即可。因此计算所有正差值的和即为所求答案。
```
class Solution {
    public int minSteps(String s, String t) {
        int length = s.length();
        int[] counts = new int[26];
        for (int i = 0; i < length; i++) {
            char c1 = s.charAt(i), c2 = t.charAt(i);
            counts[c1 - 'a']++;
            counts[c2 - 'a']--;
        }
        int steps = 0;
        for (int i = 0; i < 26; i++) {
            if (counts[i] > 0)
                steps += counts[i];
        }
        return steps;
    }
}
```
