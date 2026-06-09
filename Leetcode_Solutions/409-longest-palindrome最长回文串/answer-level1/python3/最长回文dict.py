class Solution:
    def longestPalindrome(self, s: str) -> int:
        #方法一：#使用内置模块，统计每个字符出现的次数
        dic=collections.Counter(s)  
        length=0
        maximum=0
        for i in dic.values():
            if i%2==0:
                length+=i
            else:
                length+=i-1
                maximum=1
        return length+maximum

        #方法二：新建一个字典，记录key（字符） 和 value（次数）
        # dict = {}
        # for item in s:
        #     if item not in dict: #判断该字符是否记录过
        #         dict[item] = 1
        #     else:
        #         dict[item] += 1
        # r = 0    #结果
        # flag = 0 #奇数标志位
        # for i in dict.values():
        #     if i%2 == 0:
        #         r += i
        #     else:
        #         r += i-1   # i-1为偶数，可构成回文
        #         flag = 1   # 奇数标志位，最终结果 + 1
        # return (r + flag)