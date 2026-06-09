### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
 
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        int end = wordList.indexOf(endWord);
        if (end == -1) {
            return 0;
        }
        Queue<String> q1 = new LinkedList<>();
        Queue<String> q2 = new LinkedList<>();
        Set<String> set1 = new HashSet<>();
        Set<String> set2 = new HashSet<>();
        Set<String> wordSet = new HashSet<>(wordList);
        q1.offer(beginWord);
        q2.offer(endWord);
        set1.add(beginWord);
        set2.add(endWord);
        Queue<String> q;
        Set<String> set;
        int step = 0;
        while (!q1.isEmpty() && !q2.isEmpty()) {
            if (q1.size() > q2.size()) {
                q = q2;
                q2 = q1;
                q1 = q;
                set = set2;
                set2 = set1;
                set1 = set;
            }
            int qSize = q1.size();
            ++step;
            while (qSize-- > 0) {
                char[] s = q1.poll().toCharArray();
                for (int i = 0; i < s.length; i++) {
                    char c = s[i];
                    for (char j = 'a'; j <= 'z'; j++) {
                        s[i] = j;
                        String str = new String(s);
                        
                        if (set1.contains(str)) {
                            continue;
                        }
                        if (set2.contains(str)) {
                            System.out.println(s);
                            System.out.println(str);
                            System.out.println(q1);
                            System.out.println(q2);
                            return ++step;
                        }
                        if (wordSet.contains(str)) {
                            set1.add(str);
                            q1.offer(str);
                        }
                    }
                    s[i] = c;
                }
            }
        }
        return 0;
    }

}
```