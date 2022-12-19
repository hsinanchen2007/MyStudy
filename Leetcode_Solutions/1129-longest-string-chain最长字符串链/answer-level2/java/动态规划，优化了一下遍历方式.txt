```
public static int longestStrChain(String[] words) {
        if (words == null || words.length == 0) {
            return 0;
        }
        Arrays.sort(words, Comparator.comparingInt(String::length));

        int[] dp = new int[words.length];

        dp[0] = 1;
        int res = 0;

        for (int i = 1; i < words.length; i++) {
            // 看了一下大佬们的思路，都是从头开始遍历，其实这儿可以倒着遍历，当找到满足条件的j时，0 ~ j-1的记录就不用执行了
            int j = i - 1;
            while (j >= 0) {
                if (check(words[j], words[i])) {
                    dp[i] = dp[j] + 1;
                    break;
                } else {
                    if (j == 0) {
                        dp[i] = 1;
                    }
                    j--;
                }
            }
            res = Math.max(dp[i], res);

        }
        return dp[words.length - 1];
    }

    private static boolean check(String stra, String strb) {
        int i = 0; // 字符串A的指针
        int j = 0; // 字符串B的指针
        int lenA = stra.length();
        int lenB = strb.length();
        /* 排除长度相差不为一的情况 */
        if (lenA != lenB - 1) {
            return false;
        }
        char[] a = stra.toCharArray();
        char[] b = strb.toCharArray();
        while (i < lenA && j < lenB) {
            if (a[i] == b[j]) {
                i++;
            }
            j++;
        }
        return i == lenA;
    }
```
