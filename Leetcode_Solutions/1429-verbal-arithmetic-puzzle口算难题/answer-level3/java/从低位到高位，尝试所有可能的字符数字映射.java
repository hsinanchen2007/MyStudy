1.考虑加法可能存在进位，由数字的低位(单词的高位)开始遍历，words任何一位相加再减去result不等于0，说明当前字符数字映射是错误的。
2.当第一次遇到某个字符时，从当前位开始递归，找剩余字符所对应的数字。

```
public boolean isSolvable(String[] words, String result) {
        int maxLen = 0;
        for (String word : words) {
            maxLen = Math.max(maxLen, word.length());
        }
        if (maxLen > result.length()) {
            return false;
        }
        // (char-'A') -> number(0-9);
        int[] chMap = new int[26]; // 字符索引->字符代表的数字
        Arrays.fill(chMap, -1);
        boolean[] usedVal = new boolean[10];
        int chNum = 10; // 剩余字符数
        int preVal = 0;
        int start = 1;
        return dfs(words, result, chMap, usedVal, chNum, start, preVal);
    }

    private boolean dfs(String[] words, String result, int[] chMap, boolean[] usedVal, int chNum, int start, int preVal) {
        int len = result.length();
        for (int i = start; i <= len; i++) {
            int sum = preVal;
            for (String word : words) {
                final int j = word.length() - i;
                final int val;
                if (j < 0) {
                    val = 0;
                } else {
                    final int chIndex = word.charAt(j) - 'A';
                    val = chMap[chIndex];
                    if (val == -1) {
                        if (chNum == 0) {
                            // 已经有10个字符映射关系了
                            return false;
                        } else {
                            // 找到一个映射关系 todo
                            return findNextMapping(words, result, chMap, usedVal, chNum, i, preVal, chIndex);
                        }
                    }
                }
                sum += val;
            }
            int chIndex = result.charAt(result.length() - i) - 'A';
            int res = chMap[chIndex];
            if (res == -1) {
                if (chNum == 0) {
                    // 已经有10个字符映射关系了
                    return false;
                } else {
                    // 找到一个映射关系
                    return findNextMapping(words, result, chMap, usedVal, chNum, i, preVal, chIndex);
                }
            }
            if (sum % 10 != res) {
                return false;
            }
            preVal = sum / 10;
        }
        return true;
    }

    private boolean findNextMapping(String[] words, String result, int[] chMap, boolean[] usedVal, int chNum, int i, int preVal, int chIndex) {
        for (int num = 0; num < usedVal.length; num++) {
            if (usedVal[num]) continue;
            boolean[] usedVal2 = Arrays.copyOf(usedVal, usedVal.length);
            usedVal2[num] = true;
            int[] chMap2 = Arrays.copyOf(chMap, chMap.length);
            chMap2[chIndex] = num;
            if (dfs(words, result, chMap2, usedVal2, chNum + 1, i, preVal)) {
                return true;
            }
        }
        return false;
    }

```

