```
    /**
     * 思路：滑动窗口
     * 实现：需要考虑的情况较多，非常容易出错
     * 算法复杂度：O(N)
     * 空间复杂度：O(N)
     * 用时：90 分钟
     * @param s
     * @param t
     * @param maxCost
     * @return
     *
     * 测试用例：具体见测试类
     * "abc" "bcd" 0  == 0 -- 2.1.1, 2.1.1 2.1.1
     * "abc" "zcd" 2 == 2 -- 2.1.1 1 1
     * "abcd" "zdef" 2 == 1 -- 2.1.1 2.1.2 2.1.2 2.1.2
     * 不存在   -- 2.1.1 2.2
     * "abcdef" "bcdxyz" 3 == 3 -- 1 1 1 2.1.1 2.1.1 2.1.1
     * "abcdef" "bcdxyz" 2 == 2 -- 1 1 2.2 2.1.1 2.1.1
     * "abcd" "bcdg"  3 == 3 -- 1 1 1 2.1.2
     * "abcde" "bcdgz"  3 == 3 -- 1 1 1 2.1.2 2.1.1
     * "abcd" "cddf" 5 == 3 -- 1 1 2.2 2.1.2
     * "jzmhzdq" "rymuemg" 17 -- 1 1 1 2.1.2 2.1.1
     */
    public int equalSubstring1(String s, String t, int maxCost) {
        int maxLen = 0;

        int len = s.length();
        int curGap = 0;
        int gap[] = new int[len];
        int startIndex = 0;
        for (int index = 0; index < len; index++) {
            gap[index] = Math.abs(s.charAt(index) - t.charAt(index));
            // 一开始小于 maxCost 之后大于 maxCost
            // 一开始就大于 maxCost
            if (curGap + gap[index] <= maxCost) { //1
                curGap += gap[index];
                //第一次提交这里写成了 maxLen++
                maxLen = Math.max(index - startIndex + 1, maxLen);
            } else { //2
                //分三种情况：
                //1. startIndex < index && curGap + gap[index] < maxCost
                //2. startIndex == index && curGap + gap[Index] <= maxCost
                //3. startIndex == index && curGap + gap[Index] > maxCost
                while (startIndex < index && curGap + gap[index] > maxCost) {
                    curGap -= gap[startIndex];
                    startIndex++;
                }
                if (startIndex == index) { //2.1
                    if (curGap + gap[index] > maxCost) { //2.1.1
                        startIndex++;
                        continue;
                    } else { //2.1.2
                        curGap += gap[index];
                        maxLen = Math.max(1, maxLen);
                    }
                } else { //2.2
                    curGap += gap[index];
                    maxLen = Math.max(index - startIndex + 1, maxLen);
                }
            }
        }
        return maxLen;
    }

    /**
     * 思路：滑动窗口，核心就是求解时，滑动窗口只增加不减少。实现简单，不容易出错。
     * 实现：每次不满足条件，整个窗口移动
     * 算法复杂度：O(N)
     * 空间复杂度：O(N)
     * 用时：20 分钟
     * @param s
     * @param t
     * @param maxCost
     * @return
     */
    public int equalSubstring(String s, String t, int maxCost) {
        int len = s.length();
        int gap[] = new int[len];
        for (int index = 0; index < len; index++) {
            gap[index] = Math.abs(s.charAt(index) - t.charAt(index));
        }
        int maxLen = 0;
        int curGap = 0;
        for (int gindex = 0, startIndex = 0 ; gindex < len; gindex++) {
            if (curGap + gap[gindex] > maxCost) {
                curGap = curGap + gap[gindex] - gap[startIndex];
                startIndex++;
            } else {
                curGap += gap[gindex];
                maxLen = Math.max(maxLen, gindex - startIndex + 1);
            }
        }
        return maxLen;
    }
```
