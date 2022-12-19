### 解题思路
800ms，并不容易啊小菜鸡写了好久，改了更久，不过这次值看了双端BFS这个思路，并没有看bs大佬们的代码。
写完之后看，大佬们很多都是用的set存储，而我用的是map，可能这会导致耗时c增加。
虽然有的地方可以精简，可以复用，但还是在leetcode上写这么长的

### 代码

```java []
class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if (beginWord == endWord) return 1;
        if (wordList.contains(endWord) && canArrive(beginWord, endWord)) return 2;
        // 第一次使用双端的BFS   每次都从分支少的节点出发，如果两边碰到，则得到结果
        // map保存word到字典中值各多少步
        Map<String, Integer> beginMap = new HashMap<>();
        Map<String, Integer> endMap = new HashMap<>();
        beginMap.put(beginWord, 1);
        endMap.put(endWord, 1);
        int n = wordList.size(), beginBranch = 1, endBranch = 1, beginLen = 1, endLen = 1;
        while (beginMap.size() + endMap.size() <= n + 1) {
            // 寻找分支少的
            if (beginBranch < endBranch) {
                // 最好还是先加到临时map中
                Map<String, Integer> tmpMap = new HashMap<>();
                // 对于每条路径进行遍历
                beginBranch = 0;
                int nowLen = beginLen;
                boolean noBranch = true;
                for (Map.Entry<String, Integer> en : beginMap.entrySet()) {
                    if (en.getValue() != nowLen) continue;
                    String preWord = en.getKey();
                    // 对于每个字典值进行判断
                    for (int i = 0; i < n; ++i) {
                        String nextWord = wordList.get(i);
                        if (nextWord.equals(beginWord)) continue;
                        // 如果存在原本map中，则跳过
                        if (beginMap.containsKey(nextWord)) continue;
                        // 若存在，则再加一步
                        
                        if (canArrive(preWord, nextWord)) {
                            if (noBranch) {
                                // 只改变一次路径长度
                                noBranch = false;
                                ++beginLen;
                            }
                            tmpMap.put(nextWord, beginLen);
                            if (endMap.containsKey(nextWord)) 
                                return endLen + beginLen - 1;
                            ++beginBranch;
                        }
                    }
                }
                // 再从临时map导入到另外的map
                for (Map.Entry<String, Integer> tmp : tmpMap.entrySet())
                    beginMap.put(tmp.getKey(), tmp.getValue());
            }
            else {
                Map<String, Integer> tmpMap = new HashMap<>();
                endBranch = 0;
                int nowLen = endLen;
                boolean noBranch = true;
                for (Map.Entry<String, Integer> en : endMap.entrySet()) {
                    if (en.getValue() != nowLen) continue;
                    String preWord = en.getKey();
                    for (int i = 0; i < n; ++i) {
                        String nextWord = wordList.get(i);
                        if (endMap.containsKey(nextWord)) continue;
                        // 若存在，则再加一步
                        if (canArrive(preWord, nextWord)) {
                            if (noBranch) {
                                // 只改变一次路径长度
                                noBranch = false;
                                ++endLen;
                            }
                            tmpMap.put(nextWord, endLen);                     
                            if (beginMap.containsKey(nextWord)) 
                                return beginLen + endLen - 1;
                            ++endBranch;
                        }
                    }
                }
                for (Map.Entry<String, Integer> tmp : tmpMap.entrySet())
                    endMap.put(tmp.getKey(), tmp.getValue());    
            }
            // 避免超时的退出机制: 如果双端都不存在分支，则退出
            if (endBranch == 0 || beginBranch == 0) return 0;
        }
        
        return 0;
    }

    // 判断可否到达
    boolean canArrive(String w1, String w2) {
        int n = w1.length();
        for (int i = 0; i < n; ++i) {
            // 0~i 和 i+1~n 都一样，则可以到达
            if (w1.substring(0, i).equals(w2.substring(0, i)) && w1.substring(i+1, n).equals(w2.substring(i+1, n)))   return true;
        }
        return false;
    }
}

```
