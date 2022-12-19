1. 找到罗马数字值小的排在大的前面的情况，两个相邻罗马数字都要找出来，并记录下标，这样就可以把相减的情况和值排出来；
2. 再根据下标，找出不符合上述条件的罗马数字的下标；
3. 最后把1和2的结果相加就可以了


def romanToInt(self, s: str) -> int:
        import numpy as np
        dic = {'I' : 1, 'V' : 5, 'X' : 10, 'L' : 50, 'C' : 100, 'D' : 500, 'M' : 1000}
        lst = [key for key, value in dic.items()]
        rst = []
        jl = []
        for j in range(len(s)-1):
            if dic[s[j]] < dic[s[j+1]]:
                jl.append(j)
                jl.append(j+1)
                result = dic[s[j+1]]-dic[s[j]]
                rst.append(result)

        print('需要合并的下标：',jl)
        print('合并后的数值',rst)

        il = []
        for i in range(len(s)):
            il.append(i)
        print(il)

        nls = list(set(il) ^ set(jl))
        print('除合并外的下标',nls)

        n = []
        for m in nls:
            n.append(dic[s[m]])
        print('无需合并的罗马数字值',n)

        finalResult = int(np.sum(n)+np.sum(rst))
        print(finalResult)
        return finalResult