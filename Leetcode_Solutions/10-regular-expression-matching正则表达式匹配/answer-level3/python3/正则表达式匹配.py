没有运用算法方面的知识~
import re
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m = ['.']
        n = 0
        for letter in range(97,123):
            m.append(chr(letter))
            
        #p为空，s不为空
        if len(p)==0 and len(s)!=0:
            return False
        #p不为空，s为空
        if len(s)==0 and len(p)!=0:
            if '*' not in p:
                return False
            else:
                for i in range(len(p)-1):
                    if p[i] in m:
                        if p[i+1]=='*':
                            n = i+1
                        else:
                            return False
                if n==len(p)-1:
                    return True
                else:
                    return False
        #p、s同时为空或非空       
        result = re.match(p,s)
        if result:
#            print(result.span()[1])
            if result.span()[1]!=len(s):
                return False
            else:
                return True
        else:
            return False
        
if __name__ == "__main__":
    s = ""
    p = ".*b*a"
    print(Solution().isMatch(s,p))