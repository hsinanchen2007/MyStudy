class Solution:
    def calculateTime(self, keyboard: str, word: str) -> int:
        dict1 = {}
        # 定义一个指针a，初始值为0
        a = 0
        # 定义一个数记录时间
        t = 0
        for i,num in enumerate(keyboard):
            dict1[num] = i
        for i in word:
            t += abs(a-dict1[i])
            a = dict1[i]
            
        return t