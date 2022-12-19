
暴力解法，水桶装水最短板的思路，建个字典，遍历一次计数，取最小值
```
class Solution(object):
    def maxNumberOfBalloons(self, text):
        """
        :type text: str
        :rtype: int
        """
        #建立一个字典
        dic={'b':0,'a':0,'l':0,'o':0,'n':0}
        #遍历text，记录数据
        for i in text:
            if i in dic:
                dic[i]+=1
        #返回最小的数
        return min(dic['b'],dic['a'],int(dic['l']/2),int(dic['o']/2),dic['n'])
```
