### 解题思路

思路类似于官方题解第4种解法

先计算, 再使用优先队列取出最优先的字符串返回就是

缺点: 可能没有先排序, 后计算来的高效

### 代码

```java
class Solution {
    /**
     * 感觉没啥好的思路
     * 只有遍历一种
     */
    public static String findLongestWord(String s, List<String> d) {
        PriorityQueue<Word> pq = new PriorityQueue<>();
        char[] a = s.toCharArray();
        for (int i = 0; i < d.size(); i++) {
            boolean check = check(a, d.get(i));
            if (check) {
                pq.add(new Word(d.get(i)));
            }
        }
        if (pq.isEmpty()) {
            return "";
        }
        return pq.peek().word;

    }

    private static boolean check(char[] a, String s) {
        int k = 0;

        for (char c : a) {
            if (c == s.charAt(k)) {
                k++;
            }
            if (k == s.length()) {
                return true;
            }
        }
        return false;
    }

    private static class Word implements Comparable<Word> {

        private String word;

        public Word(String word) {
            this.word = word;
        }

        @Override
        public String toString() {
            return "Word{" +
                    "word='" + word + '\'' +
                    '}';
        }

        @Override
        public int compareTo(Word o) {
            int compare = o.word.length() - this.word.length();
            if (compare != 0) {
                return compare;
            }

            return this.word.compareTo(o.word);
        }
    }


}
```