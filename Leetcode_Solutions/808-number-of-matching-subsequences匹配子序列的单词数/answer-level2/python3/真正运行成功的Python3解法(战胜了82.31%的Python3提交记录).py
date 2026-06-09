大部分的python3解法都是双重for循环，很容易超时：

                def numMatchingSubseq(self, S: str, words: List[str]) -> int:
                    count = 0
                    for word in words:
                        if self.isSubsequence(word,S):
                            count += 1

                    return count

                def isSubsequence(self, s: str, t: str) -> bool:
                    s = list(s)
                    for _t in t:
                        if not s:
                            return True
                        if _t == s[0]:
                            s.pop(0)
                    return len(s) == 0


**字典树+巧妙使用iter和next()数组**

可以利用字典树的思想，首先计算words中每个字符串的前缀，利用waiting存储{w[0]:w[1:]}形式的字典，这样就缩短了words的遍历次数：
S = "abcde"
words = ["a", "bb", "acd", "ace"]

                def numMatchingSubseq(self, S: str, words: List[str]) -> int:
                    waiting = defaultdict(list)
                    for w in words:
                        waiting[w[0]].append(iter(w[1:]))  # 存储以w[0]开头的前缀，此时waiting = {'a': [[], ['c', 'd'], ['c', 'e']], 'b': [['b']]}
                    for c in S:
                        for it in waiting.pop(c, ()):
                            waiting[next(it, None)].append(it)  # 在本题的例子中 it 分别为[]、['c', 'd']、['c', 'e']
                    return len(waiting[None])