class Solution:
    def numberOfSteps (self, num: int) -> int:
        #结果等于二进制位数-1+数位上为1的个数
        s = bin(num) #0bxx...x
        return len(s) - 2 -1 + s.count('1')