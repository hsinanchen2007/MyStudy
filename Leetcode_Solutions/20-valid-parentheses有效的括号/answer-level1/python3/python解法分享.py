人生巅峰
执行用时 :
36 ms, 在所有 Python3 提交中击败了99.66%的用户
内存消耗 :
13 MB, 在所有 Python3 提交中击败了97.37%的用户
(执行了很多次提交发现再也达不到这个水平了T.T)

给出一种很易懂菜鸟级的python解法，散列表+stack，字典的flag可以随便选（123方便点），另外加一些if判断堵漏即可:


    def isValid(self, s: str) -> bool:
        D={'(':1,'[':2,'{':3,')':-1,']':-2,'}':-3}
        re=[]
        if s=='':
            return True
        else:
            re.append(D[s[0]])
        if sum(re)<0:
            return False
        for i in s[1:]:
            if re==[]:
                re.append(D[i])
            elif D[i]+re[-1]==0:
                re.pop()
            else:
                re.append(D[i])
        return re==[]
