思路：通过统计其中4中字母的个数两两是否相等得到结果
```
class Solution(object):
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        if(moves.count('U')==moves.count('D') and moves.count('L')==moves.count('R')):
            return True
        else:
            return False
```

提交
1.执行用时：16 ms   内存消耗：12.1 MB
2.执行用时：28 ms	内存消耗：12.1 MB
------------------------------------------------------------------------------
思路：模拟走路（普通版）
```
class Solution(object):
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        lo = {'x':0,'y':0}
        #if(moves.count('U')==moves.count('D') and moves.count('L')==moves.count('R')):
        #    return True
        for i in moves:
            if(i == 'L'):
                lo['x']=lo['x']-1
            elif(i == 'R'):
                lo['x']=lo['x']+1
            elif(i == 'U'):
                lo['y']=lo['y']+1
            elif(i == 'D'):
                lo['y']=lo['y']-1
        if(lo['x']==0 and lo['y']==0):
            return True
        return False
```
提交
1.执行用时：116 ms   内存消耗：12 MB

------------------------------------------------------------------------------
思路：模拟走路（字典版）
class Solution(object):
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        lo = {'x':0,'y':0}
        #if(moves.count('U')==moves.count('D') and moves.count('L')==moves.count('R')):
        #    return True
        dic = {'R':(1,0),'L':(-1,0),'U':(0,1),'D':(0,-1)}
        x,y = 0,0
        for i in moves:
            tmp_x, tmp_y = dic[i]
            x = x + tmp_x
            y = y + tmp_y
        return x==0 and y==0
提交
1.执行用时：64 ms   内存消耗：12 MB
