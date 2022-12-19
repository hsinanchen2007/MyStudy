```
class Solution:
    def expressiveWords(self, S: str, words: List[str]) -> int:
        """
        提醒一下：题目的意思一定要搞清楚，题目的意思是说，当需要扩展的时候，例如S='helllo'，有个
                word='hello',那么只要'll'+'l' == 'lll'就是满足情况的，换句话说，当word和S中
                相应的字母数不同时，就需要扩展，当扩展的字母在S中的数量>=3,扩展就是成立的！
        思路：
        按顺序统计字母以及出现的次数，比较S和word是否满足题意即可！
        """
        # 先对S进行‘字母-出现次数’进行统计
        s_d = [[S[0], 1]]
        j = 0
        for i in range(1, len(S)):
            if S[i] == s_d[j][0]:
                s_d[j][1] += 1
            else:
                s_d.append([S[i],1])
                j += 1
        res = 0
        for word in words:
            # 设置一个坏词标记，bad==1说明这个词不满足条件
            bad = 0
            # 鲁棒性判断，S的长度<word,那么肯定无法扩展
            if len(S) < len(word):
                bad = 1
            elif len(S) == len(word):
                if S != word:
                    bad = 1
            # 对每个word进行‘字母-出现次数’进行统计
            else:
                w_d = [[word[0], 1]]
                j = 0
                for i in range(1, len(word)):
                    if word[i] == w_d[j][0]:
                        w_d[j][1] += 1
                    else:
                        w_d.append([word[i], 1])
                        j += 1
                # 统计完之后进行判断，按字母与统计数相应的规则进行判断
                if len(s_d) == len(w_d):
                    for i in range(len(s_d)):
                        # 如果字母相同
                        if s_d[i][0] == w_d[i][0]:
                            # 字母相同，但是统计数不同
                            if s_d[i][1] != w_d[i][1]:
                                # S中对应的字母小于3
                                if s_d[i][1] < 3:
                                    bad = 1
                        else:
                            bad = 1
                else:
                    bad = 1
            
            if bad == 0:
                res += 1
            
                
        return res
```
