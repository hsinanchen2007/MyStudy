循环t，在s里把s删除一个，最终s中存留的个数为需要替换的次数
这个方法刚刚过时间，时间复杂度为remove的时间复杂度*N
class Solution:
    def minSteps(self, s: str, t: str) -> int:
        s_ = list(s)
        s__ = set(s)
        t_ = list(t)
        for i in t_:
            try:
                if i in s__:
                    s_.remove(i)
            except:
                pass
        return(len(s_))