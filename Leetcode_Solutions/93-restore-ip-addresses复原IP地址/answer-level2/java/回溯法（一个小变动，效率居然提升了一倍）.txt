### 解题思路（回溯法）
分段来。IP分为4段，按次序一段一段来，不停试错。

### 一点感想
第一次知道“回溯”这个东西。参考了各位大佬的题解，自己也写了一个。
居然成功了，很开心。
再看下结果，瞬间不好了。居然9ms。暴力解法才3，4ms。
又回顾了自己的代码，看怎么优化一下。
抱着试试看的想法，把`(ipNum + "").length()` 改成了 `String.valueOf(ipNum).length()`，效率翻倍了。

下面就不知道该怎么优化了。
也复制粘贴了其他人的回溯算法，效率差不多。就先这样吧！


### 代码

```java
class Solution {
    // 每个ip段的最大和最小长度
    private int SEGMENT_LEN_MAX = 3;
    private int SEGMENT_LEN_MIN = 1;
    private int DEPTH = 4; // IP段数量（深度）

    /**
     * 回溯法
     *
     * @param s
     * @return
     */
    public List<String> restoreIpAddresses(String s) {
        List<String> ans = new ArrayList<>();

        // 小于最小长度或者 大于最大长度
        if (s.length() < SEGMENT_LEN_MIN * DEPTH 
                || s.length() > SEGMENT_LEN_MAX * DEPTH) {
            return ans;
        }

        // 存放每一段IP，如["10", "10", "0", "1"]
        String[] segmentArr = new String[DEPTH]; //
        backtrack(ans, s, 1, 0, segmentArr);

        return ans;
    }

    /**
     * 回溯
     */
    private void backtrack(List<String> ans, String s, int depth, int startIdx, String[] segmentArr) {
        String segment; // ip 段
        String ip; // 完整的ip
        for (int len = 1; len <= SEGMENT_LEN_MAX; len++) {
            // 剩下长度
            int overlen = s.length() - (startIdx + len);
            // 剩下的长度小于最小长度或大于 最大长度，跳过
            if (overlen < SEGMENT_LEN_MIN * (DEPTH - depth)
                    || overlen > SEGMENT_LEN_MAX * (DEPTH - depth)) {
                continue;
            }

            //System.out.println(startIdx + ", " + len);
            segment = s.substring(startIdx, startIdx + len);

            if (isValidSegment(segment)) {
                segmentArr[depth - 1] = segment;
                if (depth == DEPTH) {
                    ip = String.join(".", segmentArr);
                    ans.add(ip);
                } else {
                    backtrack(ans, s, depth + 1, startIdx + len, segmentArr);
                }
            }

        }
    }

    /**
     * 是否是一个有效的IP段
     * 1. 数字不以0开头，如08
     * 2. <= 255
     *
     * @param segment
     * @return
     */
    private boolean isValidSegment(String segment) {
        int ipNum = Integer.valueOf(segment);

        if (segment.length() == String.valueOf(ipNum).length()
                && ipNum <= 255) {
            return true;
        }
        return false;
    }
}
```