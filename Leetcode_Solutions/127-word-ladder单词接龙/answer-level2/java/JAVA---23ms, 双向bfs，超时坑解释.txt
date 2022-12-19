最短路径问题
双向bfs， 从beginword和endWord分别找，如果碰到则表示能转化，层数相加即可

使用双向bfs遇到的超时问题解决方式：
1. 双向找时每次遍历元素少的会减少耗时；
2. 遍历字符串时， 可以使用两种方式： 
（1） 从wordlist中能转化的字符串（当wordlist中元素多时，效率不好）；
（2） 使用’a'-'z'的依次替换（字符串长度长时效率不好）；
3. 判断元素是否在list中会遍历查找，而放到hashset中会根据key找，耗时较少

```
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if (!wordList.contains(endWord)) {
            return 0;
        }
        Queue<String> queue1 = new LinkedList<>();
        Set<String> visited1 = new HashSet<>();
        // boolean[] visited1 = new boolean[wordList.size()];
        Queue<String> queue2 = new LinkedList<>();
        Set<String> visited2 = new HashSet<>();
        // boolean[] visited2 = new boolean[wordList.size()];


        queue1.offer(beginWord);
        visited1.add(beginWord);
        queue2.offer(endWord);
        visited2.add(endWord);

        // 判断字符串是否存在时，如果使用list会线性判断，非常耗时
        // 如果不用set，可以用字典树
        Set<String> wordSet = new HashSet<>(wordList);


        int layer = 0;
        while (!queue1.isEmpty() && !queue2.isEmpty()) {            
            // 从两边长度短的一侧搜索
            if (queue1.size() > queue2.size()) {
                Queue<String> tmp = queue1;
                queue1 = queue2;
                queue2 = tmp;
                Set<String> visitedTmp = visited1;
                visited1 = visited2;
                visited2 = visitedTmp;
            }
            layer++;
            int n = queue1.size();
            while (n-- > 0) {
                String s = queue1.poll();
                char[] sChars = s.toCharArray();
                // 对每一个字母都替换成26个英文字母中的一个，看是否有满足条件的
                for (int i = 0; i < s.length(); i++) {
                    // 保留原字母，最后需要替换回去
                    char tmp = sChars[i];
                    for (char j = 'a'; j <= 'z'; j++) {
                        char newChar = j;
                        if (tmp == newChar) {
                            continue;
                        }
                        sChars[i] = newChar;
                        String newStr = new String(sChars);
                        // 不在列表中或者已经访问过，则不再判断
                        if (visited1.contains(newStr)) {
                            continue;
                        }
                        // 结束条件是： 两个visited相遇
                        if (visited2.contains(newStr)) {
                            return layer + 1;
                        }
                        if (wordSet.contains(newStr)) {
                            queue1.offer(newStr);
                            visited1.add(newStr);
                        }
                    }
                    sChars[i] = tmp;
                }
                
            }
        }
        return 0;
    }
```