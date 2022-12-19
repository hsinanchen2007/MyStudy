    def firstUniqChar(self, s):
        dic = {}
        for idx,value in enumerate(s):
            if value in dic:
                dic[value] = '?'
            else:
                dic[value] = idx
        if dic == {} or dic[min(dic,key=dic.get)] == '?':
            return " "
        else:
            return min(dic,key=dic.get)