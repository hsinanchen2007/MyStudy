### 解题思路
![Screen Shot 2020-04-09 at 02.13.30.png](https://pic.leetcode-cn.com/4b7041e3afc5affdeef398fa1b307ed890898261ec3b6fe14a729e9eb06a334b-Screen%20Shot%202020-04-09%20at%2002.13.30.png)

### 代码
```java
class Solution {
    public int minDistance(String word1, String word2) {
        if (word2.length() == 0) {
            return word1.length();
        }
        if (word1.length() == 0) {
            return word2.length();
        }

        if (word1.length() > word2.length()) {
            String tmp = word1;
            word1 = word2;
            word2 = tmp;
        }

        int N = word1.length();
        int M = word2.length();
        // 更改 word1 前i位，使得 word2 的前 j 位复位的最少操作数
        Node[][] f = new Node[N + 1][M + 1];
        f[0][0] = new Node(0, word1);
    //     for (int j = 1; j <= N; ++j) {
    //         if (word1.charAt(j - 1) != word2.charAt(j - 1)) {
    //             break;
    //         }
    //         f[j][j] = f[0][0];
    //     }
    //     // 更改 word1 的任意位，使得 word2 没有的前 0 位复位的最少操作数
    //     // 那就是不操作
    //    for (int i = 0; i <= N; ++i) {
    //        f[i][0] = f[0][0];
    //    }
        Node minOpNode = null;

        for (int i = 0; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                // 计算最少更新次数
                int minOp = Integer.MAX_VALUE;
                if (i > 0 && f[i - 1][j] != null) {
                    minOp = f[i - 1][j].opTime;
                }
                if (f[i][j - 1] != null) {
                    if (f[i][j - 1].opTime + 1 < minOp) {
                        minOp = f[i][j - 1].opTime + 1;
                    }
                }
                if (i > 0 && f[i - 1][j - 1] != null && f[i - 1][j - 1].opTime + 1 <= minOp) {
                    if (f[i - 1][j - 1].opTime + 1 < minOp) {
                        minOp = f[i - 1][j - 1].opTime + 1;
                    }

                    for (String word : f[i - 1][j - 1].words) {
                        if (word.length() < j) continue;
                        // 不用操作，可以直接转化
                        if (word.charAt(j - 1) == word2.charAt(j - 1)) {
                            if (f[i - 1][j - 1].opTime < minOp) {
                                minOp = f[i - 1][j - 1].opTime;
                            }
                            break;
                        }
                    }
                }
                if (minOp == Integer.MAX_VALUE) continue;

                // 更新数据
                f[i][j] = new Node(minOp);
                if (i > 0 && f[i - 1][j - 1] != null) {
                    if (f[i - 1][j - 1].opTime == minOp) {
                        // 不用操作，可以直接转化
                        for (String word : f[i - 1][j - 1].words) {
                            if (word.length() < j) continue;
                            if (word.charAt(j - 1) == word2.charAt(j - 1)) {
                                f[i][j].addWord(word);
                            }
                        }
                    } else {
                        f[i][j].addWords(f[i - 1][j - 1].words, 1, word2.charAt(j - 1), j, word2.length());
                    }
                }
                if (i > 0 && f[i - 1][j] != null) {
                    if (f[i - 1][j].opTime == minOp) {
                        f[i][j].addWords(f[i - 1][j].words, 0, word2.charAt(j - 1), j, word2.length());
                    }
                }
                if (f[i][j - 1] != null && f[i][j - 1].opTime + 1 == minOp) {
                    f[i][j].addWords(f[i][j - 1].words, 1, word2.charAt(j - 1), j, word2.length());
                }
                minOpNode = f[i][j];
            }
        }

        for (String str : minOpNode.words) {
            if (str.length() == word2.length()) {
                return minOpNode.opTime;
            }
        }
        return minOpNode.opTime + 1;
    }

    class Node {
        int opTime;
        Set<String> words;

        public Node(int opTime) {
            this.opTime = opTime;
            this.words = new TreeSet<>();
        }

        public Node(int opTime, String word) {
            this.opTime = opTime;
            this.words = new TreeSet<>();
            this.words.add(word);
        }

        public boolean addWord(String word) {
            return words.add(word);
        }

        public void addWords(Set<String> preWords, int op, char expectChar, int pos, int expectLen) {
            if (op == 0) {
                // 不操作
                words.addAll(preWords);
            } else {
                for (String word : preWords) {
                    if (word.length() < pos) { // 增加 1 位
                        words.add(word + expectChar);
                        continue;
                    }
                    // 新增 1 位
                    if (word.length() <= expectLen) {
                        if (pos - 1 == 0) {
                            words.add(expectChar + word.substring(pos - 1));
                        } else {
                            words.add(word.substring(0, pos - 1) + expectChar + word.substring(pos - 1));
                        }
                    }

                    // 替换 1 位 (替换掉 pos-1 位置的字符)
                    words.add(word.substring(0, pos - 1) + expectChar + word.substring(pos));

                    // 删除 1 位 (删除 pos-1 位置的字符，让 pos 位置的字符前移)
                    if (word.length() > pos && word.charAt(pos) == expectChar) {
                        words.add(word.substring(0, pos - 1) + word.substring(pos));
                    }
                }
            }
        }

        @Override
        public String toString() {
            return "Node{" +
                    "opTime=" + opTime +
                    ", words=" + words +
                    '}';
        }
    }
}
```