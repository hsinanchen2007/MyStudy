### 解题思路
看注释吧

### 感想
真不容易。失败了N次，又调整了N次。

通过后，查看了一下题解。官解里，同样是回溯，看看人家的代码。。

### 代码

```java
class Solution {
    /**
     * 经过前面的失败，准备换条路：对*的匹配使用回溯
     * 因为*可以匹配0次或N次，需要不断试错
     *
     * 计划2h，结果6h+才测试通过。。
     * 效率也不高
     *
     * @param s
     * @param p
     * @return
     */
    public boolean isMatch(String s, String p) {
        int idxStar = p.indexOf('*');

        // 回溯
        String matchStr = "";
        List<String> list = new ArrayList<String>(1);
        backtrack(s, p, 0, 0, idxStar, matchStr, list);

        return list.size() > 0;
    }

    /**
     * 回溯
     * 对 * 的匹配从0开始逐渐试错
     *
     * @param s
     * @param p
     * @param sIdx - s 开始匹配的位置
     * @param pIdx - p 开始匹配的位置
     * @param idxStar - * 最新的位置
     * @param matchStr - 已匹配的字符串
     * @param list - 完全匹配的字符串集合。有一个元素就够了
     */
    private void backtrack(String s, String p, int sIdx, int pIdx, int idxStar, String matchStr, List<String> list) {

        // 完全匹配的字符串集合。有一个元素就够了
        if (list.size() > 0) {
            return;
        }

        if (idxStar == -1) {
            // 已经接近或到达末尾

            boolean match = false;
            // 大致2种情形
            // 1, s 和 p 同时到达末尾，match
            // 2, 没有结束继续比较
            if (sIdx == s.length() && pIdx == p.length()) {
                // 1
                match = true;
            } else {
                // 2
                // 不会含有 *
                match = compareWithoutStar(s.substring(sIdx), p.substring(pIdx));
            }

            if (match) {
                list.add(matchStr);
                return;
            }
        } else {
            int len = idxStar - pIdx - 1; // * 及前面一个字符不算，即不参与比较

            if (len > 0) {
                // s 结束，p 还未结束
                if (sIdx + len > s.length()) {
                    return;
                }

                String sStr = s.substring(sIdx, sIdx + len); // s 的比较片段
                if (compareWithoutStar(sStr, p.substring(pIdx, pIdx + len))) {
                    // 匹配则继续
                    matchStr += sStr;
                    sIdx += len;
                } else {
                    // 普通字符都不等，
                    return;
                }
            }

            // 开始对 * 进行匹配
            char beforeStar = p.charAt(idxStar - 1); // * 前面的字符
            pIdx = idxStar + 1;
            idxStar = p.indexOf('*', pIdx);

            // 匹配次数
            int matchTimes = 0;

            while (list.isEmpty() && sIdx + matchTimes <= s.length()) {
                if (matchTimes > 0 && s.charAt(sIdx + matchTimes - 1) != beforeStar && beforeStar != '.') {
                    return;
                }

                if (matchTimes > 0) {
                    matchStr += s.charAt(sIdx + matchTimes - 1);
                }

                backtrack(s, p, sIdx + matchTimes, pIdx, idxStar, matchStr, list);

                matchTimes ++;
            }
        }
    }

    /**
     * 比较 s2 不含 * 的字符串
     *
     * @param s1
     * @param s2
     */
    private boolean compareWithoutStar(String s1, String s2) {
        if (s1.length() != s2.length()) {
            // 长度不等，一定不匹配
            return false;
        }

        if (s2.indexOf('.') == -1) {
            // 不含匹配符，直接比较字符串
            return s1.equals(s2);
        } else {
//            for (int i = 0; i < s1.length(); i++) {
//                if (s1.charAt(i) != s2.charAt(i) && s2.charAt(i) != '.') {
//                    return false;
//                }
//            }

            // 跟 上面 挨个比，没啥区别
            int from = 0, end = 0;

            while (true) {
                end = s2.indexOf('.', end);

                if (end == -1) {
                    return s1.substring(from).equals(s2.substring(from));
                }

                if (end - from > 0 && ! s1.substring(from, end).equals(s2.substring(from, end))) {
                    return false;
                }

                end ++;
                from = end;

            }
        }

    }

}
```