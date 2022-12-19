class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if not p: 
            return not s

        firstM = bool(s and p[0] in [s[0], '.'])  # p == []的边界很好找，但是 s == []的边界不好找，但是s=[]并不是边界，可以分解出子问题，就是当p[1]是 * 的时候 那么子问题是 self.isMatch(s,p[2:]),如果不是*的话那么直接是False,所以  firstM要在s为[]的时候判定为False,然后走firstM直接判负

        # 抽象的 firstM的写法，此时要思考当s=[]时候  什么情况下算firstM（就是分支的第二种情况），然后
        # 写第一个条件下的判断，实在不行可以加条件，但是我们发现，就是self.isMatch(s, p[2:])的情况
        if len(p) >=2 and p[1] == '*':
            return self.isMatch(s, p[2:]) or firstM and self.isMatch(s[1:],p)  
        else:
            return firstM and self.isMatch(s[1:], p[1:])


class Solution:  # 不用考虑firstM抽象情况的写法
    def isMatch(self, s: str, p: str) -> bool:
        if not p: 
            return not s
        if not s:
            if len(p)%2 ==0:
                for i in range(1,len(p),2):
                    if p[i]!='*':
                        return False
                return True
            else:
                return False
        firstM = p[0] in [s[0], '.']  # p == []的边界很好找，但是 s == []的边界不好找，但是s=[]并不是边界，可以分解出子问题，就是当p[1]是 * 的时候 那么子问题是 self.isMatch(s,p[2:]),如果不是*的话那么直接是False,所以  firstM要在s为[]的时候判定为False,然后走firstM直接判负
        if len(p) >=2 and p[1] == '*':
            return self.isMatch(s, p[2:]) or firstM and self.isMatch(s[1:],p)  
        else:
            return firstM and self.isMatch(s[1:], p[1:])