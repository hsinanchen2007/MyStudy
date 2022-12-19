1.把ip拆成4位,  每位只有【1，2，3】（cand）三种可能性。
2.字符串长度n下合理的组合。比如 10 = 【3，3，3，1】【3，3，1，3】【3，1，3，3】【1，3，3，3】（通过left）
3.判断是否满足ip要求 （num）



class Solution:

    def restoreIpAddresses(self, s: str) -> List[str]:   
        n = len(s)
        if n== 0:
            return []

        #ip每一位只有1-3位数
        cand = [1,2,3]
        path, res ,tmp= [], [], []
        self.dfs(cand, 0,  path, res , n, s, 0)


        for arr in res:
            tmp.append(".".join(arr))
        return tmp
    

    def dfs(self,cand, level, path, res,  n, s, begin):
        #边界条件      
        if level == 4 :
            if n == 0:
                res.append(path[:])

            return

        for idx in cand:
            #剩下的字符串多长
            left = n - idx

            #判断能不能作为ip
            num =  s[begin: begin +idx]                            
            if left< 0 or int(num) > 255 or num != str(int(num)):
                break 


            path.append(s[begin: begin+idx])
            self.dfs(cand, level+1, path, res, left, s, begin+idx)
            path.pop()