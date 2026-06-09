**思路**
1. 首先，将所有出现的字符（包括words和result）放到一个list中；
2. 然后，类似全排列的思路，暴力搜索所有的排列（由于题目也说了，不同字符数最大就是10，而10!也就300多万，再算上计算方程的时间$(5*7)$, 大概要计算1亿次，理论上还是可以接受），比如$[A,B,C,D,E]$的字符列表可以映射为$[1,2,3,5,8]$,也可以映射为$[2,5,7,8,9]$。相当于暴力枚举所有的排列。若发现某一排列可以满足要求，就无需继续递归，可直接返回。递归遍历过程中用到了一个数组来充当map，用来记录映射关系（如果使用hashMap的话，有超时的风险）。
3. 其中，当得到一个排列的时候，就拿这个排列对应的map数组去计算是否满足 **左侧数字之和（words）等于右侧数字（result）** 即可。

```java
public class Problem04 {

    private String[] words;
    private String result;
    private List<Character> charList;
    private int charSize;
    private boolean[] nonZero;

    // 判断当前映射组合能否让方程可解。sum(word[i]) = result
    private boolean isMatch(int[] map) {
        int sum = 0;
        for (String word: words) {
            int tmp = 0;
            for (char c : word.toCharArray()) {
                tmp *= 10;
                tmp += map[c - 'A'];
            }
            sum += tmp;
        }

        int resultValue = 0;
        for (char c : result.toCharArray()) {
            resultValue *= 10;
            resultValue += map[c - 'A'];
        }

        return sum == resultValue;
    }

    private boolean backTrack(int from, boolean[] visited, int[] map) {
        if (from == charSize) {
            return isMatch(map);
        }

        char curChar = charList.get(from);
        for (int i = 0; i <= 9; i++) {
            if (i == 0 && nonZero[curChar - 'A'] || visited[i]) {
                continue;
            }

            visited[i] = true;
            map[curChar - 'A'] = i;
            boolean isMatch = backTrack(from + 1, visited, map);
            if (isMatch) {
                return true;
            }
            visited[i] = false;
        }

        return false;
    }

    public boolean isSolvable(String[] words, String result) {
        this.words = words;
        this.result = result;
        int resLen = result.length();
        Set<Character> set = new HashSet<>();
        nonZero = new boolean[26];
        for (String word: words) {
            if (word.length() > resLen) {
                return false;
            }

            nonZero[word.charAt(0) - 'A'] = true;
            for (char c : word.toCharArray()) {
                set.add(c);
            }
        }

        nonZero[result.charAt(0) - 'A'] = true;
        for (char c : result.toCharArray()) {
            set.add(c);
        }

        charList = new ArrayList<>(set);
        charSize = charList.size();

        int[] map = new int[26];
        Arrays.fill(map, -1);
        return backTrack(0, new boolean[10], map);
    }

}
```
**时间复杂度分析**
$10! * 5 * 7 ≈ 1$亿。理论上一两秒。

