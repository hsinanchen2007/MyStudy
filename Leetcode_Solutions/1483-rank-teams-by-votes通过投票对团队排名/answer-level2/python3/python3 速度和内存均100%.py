import functools
class Solution:
    def cmp(self, a, b):
        """
        自定义cmp函数，a>b的情况
        此时默认排序是从小到大
        """
        for i in range(len(a[1])):
            if a[1][i] > b[1][i]:
                return 1
            elif a[1][i] < b[1][i]:
                return -1
        
        if a[0] < b[0]:
            return 1
        else:
            return -1
            
    def rankTeams(self, votes: List[str]) -> str:
        # zimu => 'A':[0,1,2]
        zimu = {}
        llen = len(votes[0])
        for vote in votes:
            for idx, zm in enumerate(vote):
                if zm not in zimu.keys():
                    zimu[zm] = [0] * llen
                zimu[zm][idx] += 1
        
        # 得到了每个字母出现票位置的频率
        zimu = [(k,v) for k,v in zimu.items()]
        zimu.sort(key=functools.cmp_to_key(self.cmp), reverse=True)
        res = "".join(list([k[0] for k in zimu]))
        return res

1 将每个字符出现的次数存储起来
比如['ABC', 'BAC']
那么此时 A=>[1,1,0] B=>[1,1,0] C=>[0,0,2]
zimu 存储的是每个字符，在所有给定字符串中每个位置出现的次数,如上:
A 在0号位置出现1次，1号1次，0号 3次

2 根据要求，使用自定义排序即可
