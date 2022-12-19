建立2个hash表，1个用来存放small中
small中的每个字符串的首字母作为key 把这个所有首字母一样的hash到一个
然后遍历字符串 这样small表中同样的字母就可以一起来计算
因为返回的是有序的 另外一个用来存放字符串出现的位置

class Solution(object):
    def multiSearch(self, big, smalls):
        """
        :type big: str
        :type smalls: List[str]
        :rtype: List[List[int]]
        """
        hashsmalls = {}
        count = {}
        res = []
        if len(big) == 0:
            return [[] for _ in range(len(smalls))]
        if len(smalls) == 0:
            return []
        for item in smalls:
            if len(item) == 0:
                count[item] = [] 
                continue
            if item[0] not in hashsmalls:
                hashsmalls[item[0]] = [item]
            else:
                hashsmalls[item[0]].append(item)
            count[item] = []
        
        for i in range(len(big)):
            if big[i] not in hashsmalls:
                continue
            for item in hashsmalls[big[i]]:
                if item == big[i:i+len(item)]:
                    count[item].append(i)
        for item in smalls:
            res.append(count[item])
        return res