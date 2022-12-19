![image.png](https://pic.leetcode-cn.com/5d54210b7208481e71152aa39018b8133026edbd4199c7b79558e56aec249392-image.png)

没什么算法，就是模拟放置，空格计算涉及到取商和取余。

```python []
class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        l = {c: len(c) for c in words}   #单词长度用的多，最好提前先算好哈希化
        tl = 0      #每行纯单词累计长度
        tn = 0      #每行内临时单词个数
        tc = []     #每行临时放置单词列表
        ans = []
        for c in words:
            tl += l[c]
            tn += 1
            tc += [c]
            if tl + tn - 1 == maxWidth:   #如果刚好放置就直接输出
                ans += [' '.join(tc)]
                tl = 0
                tn = 0
                tc = []         #下一行从空列表开始放
            elif tl + tn - 1 > maxWidth:        #放置单词超出行限了
                if tn > 2:      #放置超过1个词的情况，判断大于2是因为实际上多放了一个词
                    tk = maxWidth - (lc - l[c]) #空格总长度
                    tn -= 2     #间隔数
                    quo = tk // tn
                    ram = tk % tn
                    tans = ''   #临时行输出
                    for i in range(tn):
                        tans += tc[i] + ' ' * quo#间隔长度是总空格数tk除以间隔数tn的商
                        if i < ram:
                            tans += ' '     #小于余数的间隔就加一个空格
                    ans += [tans + tc[-2]]  #再加上除去多出来的单词以外的最后一个单词
                else:   #只放一个词的情况
                    ans += [tc[0] + ' ' * (maxWidth - l[tc[0]])]
                tl = l[c]
                tn = 1
                tc = [c]    #临时放置列表恢复成只放当前单词
        if tn > 0:          #如果临时放置列表里还有单词就按规则再输出最后一行
            ans += [' '.join(tc) + ' ' * (maxWidth - tl - tn + 1)]
        return ans
```
