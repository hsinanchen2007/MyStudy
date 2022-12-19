### 解题思路
此处撰写解题思路

### 代码


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        coins = sorted(list(set(coins)),key = lambda x:-x)
        lenc,d = len(coins),{}
        def helper(c,resi):
            ci = coins[c]
            if resi%ci==0:
                return  resi//ci
            if c==lenc-1:
                return 100000
            used0=100000
            for i in range((resi//ci),-1,-1):
                resi_n = resi-i*ci
                if (c+1,resi_n) not in d:
                    d[(c+1,resi_n)] = helper(c+1,resi_n)
                used0 = min(used0,d[(c+1,resi_n)]+i) 
                if used0<100000 and i <=(resi-(used0)*coins[c+1])//(ci-coins[c+1]):
                        break
            return used0 
        res = helper(0,amount) 
        return res if res<100000 else -1
        
        
