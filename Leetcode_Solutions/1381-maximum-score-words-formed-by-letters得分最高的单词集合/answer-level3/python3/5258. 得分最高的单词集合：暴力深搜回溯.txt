![image.png](https://pic.leetcode-cn.com/f3c68ac0bf77766006ca5f273a34e089979f1eac0011225b79791462986405a0-image.png)

看起来像背包，不过数据好像很小，所以就直接深搜回溯了。

用`Counter`容器的`subtract`方法来检验记录是否可以放入第`i`号单词，剩下的就是普通DFS的工作了了，80ms仅供参考。

注意扩展的时候要对计数字典进行浅拷贝才行，直接引用字典指针是无法得到正确答案的。

缺陷也是有的，传参拷贝太多，影响了时间，总体马马虎虎吧。

```python []
class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        a = {chr(97 + i): s for i, s in enumerate(score)}   #字母对应分数的哈希字典
        b = [collections.Counter(w) for w in words]         #第i个词字母统计
        d = [*map(lambda w: sum(a[c] for c in w), words)]   #第i个词对应的分数
        n = len(words)
        def f(i, r, p):     #参数(单词序号i, 累计分数r, 剩余可以使用的计数容器p)
            if i == n:      #深搜到底时返回累计分数
                return r
            else:
                t = f(i + 1, r, p)  #不放单词时的深搜扩展
                q = p.copy()        #放单词时的深搜扩展，需要进行浅拷贝
                q.subtract(b[i])    #Counter容器的减技术
                if all(q[c] >= 0 for c in q):   #超容判断
                    t = max(t, f(i + 1, r + d[i], q))
                return t
        return f(0, 0, collections.Counter(letters))
```
