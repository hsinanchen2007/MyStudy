class Solution:
    def longestCommonPrefix(self, strs):
        # 判断strs中是否有值，没有返回""
        if len(strs) == 0:
            return ""

        # 令tmp = 第一个值
        tmp = strs[0]

        # 比较轮数
        for i in range(1,len(strs)):

            # 相同的前缀数量
            num = 0

            # 每两个字符串比较，次数为短的字符串长度
            # 前缀相同，则num = num+1
            # 最后返回相同的字符串，赋值给tmp
            # 进行下一轮
            for j in range(min(len(tmp),len(strs[i]))):
                if tmp[j] == strs[i][j]:
                    num +=1
                elif num == 0:
                    return ""
            tmp = tmp[:num]
        return tmp
                