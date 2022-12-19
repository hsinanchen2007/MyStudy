一开始想到的是把每个字符出现的位置都记录下来，那么假设对于某个字符'a'，如果它的索引为i，则需要在它之后找到第一次出现'b'的位置j、第一次出现'c'的位置k，子串s.substring(i,Math.max(j,k)+1)、s.substring(i,Math.max(j,k)+2)、s.substring(i,Math.max(j,k)+3)……s.substring(i,length)都是符合要求的，一共有(length-Math.max(j,k))个子串。对于字符'b'和'c'也是这样处理。

```
class Solution {
    public int numberOfSubstrings(String s) {
        int result = 0;
        int length = s.length();
        /**
         * 按顺序记录"a"所在的索引位置
         */
        List<Integer> aIndexes = new ArrayList<>();
        /**
         * 按顺序记录"b"所在的索引位置
         */
        List<Integer> bIndexes = new ArrayList<>();
        /**
         * 按顺序记录"c"所在的索引位置
         */
        List<Integer> cIndexes = new ArrayList<>();

        for (int i = 0; i < length; i++) {
            char c = s.charAt(i);

            if (c == 'a') {
                aIndexes.add(i);
            } else if (c == 'b') {
                bIndexes.add(i);
            } else {
                cIndexes.add(i);
            }
        }

        for (int i = 0; i < length; i++) {
            char c = s.charAt(i);

            if (c == 'a') {
                /**
                 * 这个"a"之后"b"最早出现的索引位置
                 */
                int bIndex = help(bIndexes, i);
                /**
                 * 这个"a"之后"c"最早出现的索引位置
                 */
                int cIndex = help(cIndexes, i);
                /**
                 * 如果这个"a"之后"b"和"c"都存在，则以索引i开始，以Math.max(bIndex,cIndex)
                 * 索引结尾的子串符合要求，并且这之后所有的索引结尾的子串都符合要求
                 */
                if (bIndex != -1 && cIndex != -1) {
                    result += (length - Math.max(bIndex, cIndex));
                }
            } else if (c == 'b') {
                /**
                 * 这个"b"之后"a"最早出现的索引位置
                 */
                int aIndex = help(aIndexes, i);
                /**
                 * 这个"b"之后"c"最早出现的索引位置
                 */
                int cIndex = help(cIndexes, i);
                /**
                 * 如果这个"b"之后"a"和"c"都存在，则以索引i开始，以Math.max(aIndex,cIndex)
                 * 索引结尾的子串符合要求，并且这之后所有的索引结尾的子串都符合要求
                 */
                if (aIndex != -1 && cIndex != -1) {
                    result += (length - Math.max(aIndex, cIndex));
                }
            } else {
                /**
                 * 这个"c"之后"a"最早出现的索引位置
                 */
                int aIndex = help(aIndexes, i);
                /**
                 * 这个"c"之后"b"最早出现的索引位置
                 */
                int bIndex = help(bIndexes, i);
                /**
                 * 如果这个"c"之后"a"和"b"都存在，则以索引i开始，以Math.max(aIndex,bIndex)
                 * 索引结尾的子串符合要求，并且这之后所有的索引结尾的子串都符合要求
                 */
                if (aIndex != -1 && bIndex != -1) {
                    result += (length - Math.max(aIndex, bIndex));
                }
            }
        }
        return result;
    }
    
    /**
     * 在indexes中二分查找大于i的最小值，如果找不到返回-1
     *
     * @param indexes
     * @param i
     * @return
     */
    private int help(List<Integer> indexes, int i) {
        /**
         * 如果indexes中没有元素或者最后一个元素也不大于i，则indexes中没有大于i的元素，返回-1
         */
        if (indexes.isEmpty() || i >= indexes.get(indexes.size() - 1)) {
            return -1;
        }

        int lo = 0;
        int hi = indexes.size() - 1;

        while (lo < hi) {
            int mid = (lo + hi) / 2;

            if (indexes.get(mid) < i) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return indexes.get(hi);
    }
}
```

但是其实，只要从后向前遍历一遍字符串s记录下当前'a'、'b'、'c'最早出现的索引位置即可。

```
class Solution {
    public int numberOfSubstrings(String s) {
        int result = 0;
        /**
         * 当前字符之后第一个出现的"a"的索引位置
         */
        int aIndex = Integer.MAX_VALUE;
        /**
         * 当前字符之后第一个出现的"b"的索引位置
         */
        int bIndex = Integer.MAX_VALUE;
        /**
         * 当前字符之后第一个出现的"c"的索引位置
         */
        int cIndex = Integer.MAX_VALUE;
        int length = s.length();

        for (int i = length - 1; i >= 0; i--) {
            char c = s.charAt(i);

            if (c == 'a') {
                aIndex = Math.min(aIndex, i);
                /**
                 * 如果当前字符"a"之后"b"和"c"都出现过，则以索引i开始，以Math.max(bIndex,cIndex)
                 * 索引结尾的子串符合要求，并且这之后所有的索引结尾的子串都符合要求
                 */
                if (bIndex != Integer.MAX_VALUE && cIndex != Integer.MAX_VALUE) {
                    result += (length - Math.max(bIndex, cIndex));
                }
            } else if (c == 'b') {
                bIndex = Math.min(bIndex, i);
                /**
                 * 如果当前字符"b"之后"a"和"c"都出现过，则以索引i开始，以Math.max(aIndex,cIndex)
                 * 索引结尾的子串符合要求，并且这之后所有的索引结尾的子串都符合要求
                 */
                if (aIndex != Integer.MAX_VALUE && cIndex != Integer.MAX_VALUE) {
                    result += (length - Math.max(aIndex, cIndex));
                }
            } else {
                cIndex = Math.min(cIndex, i);
                /**
                 * 如果当前字符"c"之后"a"和"b"都出现过，则以索引i开始，以Math.max(aIndex,bIndex)
                 * 索引结尾的子串符合要求，并且这之后所有的索引结尾的子串都符合要求
                 */
                if (aIndex != Integer.MAX_VALUE && bIndex != Integer.MAX_VALUE) {
                    result += (length - Math.max(aIndex, bIndex));
                }
            }
        }
        return result;
    }
}
```
