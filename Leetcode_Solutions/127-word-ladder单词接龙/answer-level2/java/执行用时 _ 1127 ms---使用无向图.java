### 解题思路
使用wordList初始化无向图，相差一个字母的才能连接
![微信图片_20200228114235.jpg](https://pic.leetcode-cn.com/a10c08f87b856c17ea048f5e3e76a3a507aba923e64d7206f8557465fedb111b-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200228114235.jpg)


### 代码

```java
class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if (beginWord == null || endWord == null ||
                beginWord.length() == 0 ||
                beginWord.length() != endWord.length() ||
                !wordList.contains(endWord)) {
            return 0;
        }

        // init graph
        int[][] graph = new int[wordList.size()][wordList.size()];
        for (int i = 0; i < wordList.size(); i ++) {
            for (int j = i + 1; j < wordList.size(); j ++) {
                if (i == j) {
                    continue;
                }

                graph[i][j] = graph[j][i] = chayige(wordList.get(i), wordList.get(j));
            }
        }

        int endIndex = wordList.indexOf(endWord);
        int res = 2;

        boolean[] isVisited = new boolean[wordList.size()];
        LinkedList<Integer> queue = new LinkedList<>();
        for (int i = 0; i < wordList.size(); i ++) {
            if (chayige(beginWord, wordList.get(i)) == 1) {
                queue.add(i);
                isVisited[i] = true;

                if (i == endIndex) {
                    return res;
                }
            }
        }

        while (queue.size() > 0) {
            res ++;
            int size = queue.size();
            while (size -- > 0) {
                int index = queue.poll();
                int[] g = graph[index];
                for (int i = 0; i < g.length; i ++) {
                    if (g[i] == 1 && !isVisited[i]) {
                        queue.add(i);
                        isVisited[i] = true;

                        if (i == endIndex) {
                            return res;
                        }
                    }
                }
            }
        }

        if (isVisited[endIndex]) {
            return res;
        }
        
        return 0;
    }

    private int chayige(String s1, String s2) {
        int res = 0;
        for (int i = 0; i < s1.length(); i ++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                res ++;
                if (res > 1) {
                    return 0;
                }
            }
        }

        return res;
    }
}
```