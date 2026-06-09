## 思路:

一看这一题就是`BFS`,

```python
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        from collections import deque
        wordList = set(wordList)
        if endWord not in wordList:
            return 0
        visited = set()
        # 看两个单词是否差一个字母
        def is_one_letter(w, word):
            if len(w) != len(word) :
                return False
            dif = 0
            for i in range(len(w)):
                if w[i] != word[i]:dif += 1
                if dif > 1: return False
            return True
        # 发现所有和word相差一个字母的单词
        def find_only_one_letter(word):
            ans = []
            for w in wordList:
                #print(is_one_letter(w, word))
                if w not in visited and is_one_letter(w, word):
                    ans.append(w)
            #print(ans)
            return ans
        queue = deque()
        queue.appendleft(beginWord)
        res = 1
        # BFS
        while queue:
            n = len(queue)
            for _ in range(n):
                tmp = queue.pop()
                if tmp == endWord:
                    return res
                visited.add(tmp)
                for t in find_only_one_letter(tmp):
                    queue.appendleft(t)
            res += 1
        return 0
```

但是, 上面才过了`29/40`测试用例,可能是由于每次都要和`wordList`比较是否是差一个单词, 换个其他方法.

```python
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        from collections import deque
        wordList = set(wordList)
        if endWord not in wordList:
            return 0
        visited = set()
        queue = deque()
        queue.appendleft(beginWord)
        # 单词长度
        word_n = len(beginWord)
        res = 1
        # BFS
        while queue:
            n = len(queue)
            for _ in range(n):
                tmp = queue.pop()
                # 等于endWord
                if tmp == endWord:
                    return res
                # 访问过的删除
                if tmp in wordList:
                    wordList.remove(tmp)
                for i in range(word_n):
                    for a in range(97, 123):
                        w = tmp[:i] + chr(a) + tmp[i+1:]
                        #print(w)
                        if w in wordList:
                            queue.appendleft(w)
            res += 1
        return 0
```

上面过了`30/40`(只多过一个),哈哈,还是不行!再优化, 换一个`BFS`框架,

```python
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        from collections import deque
        wordList = set(wordList)
        if endWord not in wordList:
            return 0
        visited = set()
        cur = set()
        cur.add(beginWord)
        # 单词长度
        word_n = len(beginWord)
        res = 1
        # BFS
        while cur:
            next_time = set()
            if endWord in cur:
                return res
            for tmp in cur:
                if tmp in wordList:
                    wordList.remove(tmp)
                for i in range(word_n):
                    for a in range(97, 123):
                        w = tmp[:i] + chr(a) + tmp[i+1:]
                        if w in wordList:
                            next_time.add(w)
            res += 1
            cur = next_time
        return 0
```

终于经过各种操作, 终于可以过了, 但是速度还是太慢

网上看到一个技巧, 就是`beginWord`和`endWord`一起走, 什么意思呢?就是说`beginWord`找`endWord`,`endWord`找`beginWord`,直接看代码也很好理解的!

```python [1]
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList:
            return 0
        wordict = set(wordList)
        s1 = {beginWord}
        s2 = {endWord}
        n = len(beginWord)
        step = 0
        wordict.remove(endWord)
        while s1 and s2:
            step += 1
            if len(s1) > len(s2): s1, s2 = s2, s1
            s = set()
            for word in s1:
                nextword = [word[:i] + chr(j) + word[i + 1:] for j in range(97, 123) for i in range(n)]
                for w in nextword:
                    if w in s2:
                        return step + 1
                    if w not in wordict: continue
                    wordict.remove(w)
                    s.add(w)
            s1 = s
        return 0
```



```java [1]
class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> wordSet = new HashSet<>(wordList.size());
        wordSet.addAll(wordList);
        if (!wordSet.contains(endWord)) return 0;
        Set<String> s1 = new HashSet<>();
        Set<String> s2 = new HashSet<>();
        s1.add(beginWord);
        s2.add(endWord);
        int n = beginWord.length();
        int step = 0;
        while (!s1.isEmpty() && !s2.isEmpty()) {
            step++;
            if (s1.size() > s2.size()) {
                Set<String> tmp = s1;
                s1 = s2;
                s2 = tmp;
            }
            Set<String> s = new HashSet<>();
            for (String word : s1) {
                for (int i = 0; i < n; i++) {
                    char[] chars = word.toCharArray();
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        chars[i] = ch;
                        String tmp = new String(chars);
                        if (s2.contains(tmp)) return step + 1;
                        if (!wordSet.contains(tmp)) continue;
                        wordSet.remove(tmp);
                        s.add(tmp);
                    }
                }
            }
            s1 = s;
        }
        return 0;        
    }
}
```