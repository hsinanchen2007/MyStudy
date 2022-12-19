### 解题思路
参考的官方解题,回溯法,自己实现的时候也是这个思路,不过可能细节没注意一直没通过,然后参考的官方解题.

### 代码

```java
/*
 * Copyright (c) 2020
 * @Author:xiaoweixiang
 */


import java.util.*;

class Solution {
    public static void main(String[] args) {
        String s = "catsanddog";
        List<String> wordDict = new ArrayList<>(Arrays.asList("cat", "cats", "and", "sand", "dog"));
        Solution solution = new Solution();
        solution.wordBreak(s, wordDict).forEach(ss -> System.out.println("ss = " + ss));
    }

    /**
     * 参考官方解题,回溯法清晰简单
     *
     * @param s
     * @param wordDict
     * @return
     */
    public List<String> wordBreak(String s, List<String> wordDict) {
        HashSet<String> set = new HashSet<>(wordDict);
        return word_Break(s, set, 0);

    }

    HashMap<Integer, List<String>> map = new HashMap<>();

    public List<String> word_Break(String s, Set<String> wordDict, int start) {
        if (map.containsKey(start)) {
            return map.get(start);
        }
        ArrayList<String> res = new ArrayList<>();
        if (start == s.length()) {
            res.add("");
        }
        for (int end = start + 1; end <= s.length(); end++) {
            if (wordDict.contains(s.substring(start, end))) {
                List<String> list = word_Break(s, wordDict, end);
                for (String l : list) {
                    res.add(s.substring(start, end) + (l.equals("") ? "" : " ") + l);
                }
            }
        }
        map.put(start, res);
        return res;
    }

}
```