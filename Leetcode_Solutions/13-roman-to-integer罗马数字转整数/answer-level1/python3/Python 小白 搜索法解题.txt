class Solution(object):
    def romanToInt(self, s):
        dict1 = {'I':1,'IV':4,'V':5,'IX':9,'X':10,'XL':40,'L':50,'XC':90,'C':100,'CD':400,'D':500,'CM':900,'M':1000} #创建字典包含所有可能的值对应情形
        M = ['IV','IX','XL','XC','CD','CM'] #创建特殊值的键列表
        A = str(s)
        L=[]
        for i in M:                         # 如果i在M里
            if i in A:                      # 且i在A里
                A = A.replace(i,'')         #去除i
                L.append(dict1[i])          #将i的值保存在L内
        C = list(A)                         #将去除特殊值的字符串列表化
        for j in C:
            L.append(dict1[j])              #遍历C，并将对应值加入L
        return sum(L) #求和