因为最短的距离只会出现在直接相邻的两个单词之间，所以只需要记录最新出现的单词位置并进行计算
每一次检测到目标单词就更新一次距离，比较直观
```
class Solution:
    def findClosest(self, words: List[str], word1: str, word2: str) -> int:
        w1_idx = -1
        w2_idx = -1
        dis = 200000
        for i in range(len(words)):
            if words[i] == word1:
                w1_idx = i
            if words[i] == word2:
                w2_idx = i
            if w1_idx>=0 and w2_idx>=0:
                tmp_dis = abs(w1_idx - w2_idx)
                if tmp_dis<dis:
                    dis = tmp_dis
        return dis
```
