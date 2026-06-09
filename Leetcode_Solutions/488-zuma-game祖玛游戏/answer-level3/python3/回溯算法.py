1. 是一个优化枚举的方法，迭代过程中每次打出一个球，更新board和hand，然后利用DFS求解
2. 设立一些剪枝条件可以优化速度，不然容易TLE
3. 时间复杂度o(((n+m)!m!/n!),n<=20,m<=5
```
from collections import defaultdict
class Solution:
    def findMinStep(self, board: str, hand: str) -> int:
        def elimination(s,start):
            if start < 0:
                return s
            #从start开始对s进行消去
            len_s = len(s)
            if len_s <= 2:
                return s
            l = start
            r = start
            while l > 0 and s[l-1] == s[start]:
                l -= 1
                if l == 0:
                    break
            while r < len_s-1 and s[r+1] == s[start]:
                r += 1
                if r == len_s - 1:
                    break
            if r - l <= 1:
                return s
            else:
                temp = s[:l] + s[r+1:]
                return elimination(temp,l-1)
        
        #检查剩余手上的球是否还能消去所有球，如果不能直接返回-1
        board_balls = defaultdict(int)
        hand_balls = defaultdict(int)
        for i in board:
            board_balls[i] += 1
        for i in hand:
            hand_balls[i] += 1
        for i in board_balls:
            if board_balls[i] + hand_balls[i] <3:
                return -1
                    
        played_hand = set()  #记录本回合打过的球的种类，不重复打，剪枝操作
        n = len(board)
        m = len(hand)
        if n == 0:
            return 0
        if m == 0:
            return -1
        ans =6 #球只有5种，6相当于无穷大
        flag = 0
        #如果手牌中有一种球board里面只有一个，那么先打出去，不需要分枝
        for i in range(m):
            if board_balls[hand[i]] == 1:
                flag = 1
                for j in range(n):
                    if board[j] == hand[i]:
                        temp = board[:j] + hand[i] + board[j:]
                        temp = elimination(temp,j)
                        z = self.findMinStep(temp,hand[:i]+hand[i+1:])
                        if z >= 0:
                            ans = min(ans,z)
                break
                
        #通过递归来实现回溯算法        
        if flag == 0:        
            for i in range(m):
                if hand[i] in played_hand:
                    continue
                else:
                    played_hand.add(hand[i])
                    for j in range(n):
                        if j > 0 and board[j] == board[j-1]:
                            continue
                        if j < n-1 and hand[i] != board[j]:
                            continue
                        temp = board[:j] + hand[i] + board[j:]
                        temp = elimination(temp,j)
                        z = self.findMinStep(temp,hand[:i]+hand[i+1:])
                        if z >= 0:
                            ans = min(ans,z)
    
        return ans+1 if ans != 6 else -1
```
