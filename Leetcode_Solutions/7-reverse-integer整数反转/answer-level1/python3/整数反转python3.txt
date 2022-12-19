'''
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
示例 1:
输入: 123
输出: 321
假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
'''
class Solution():
    def fun(self):
        num = int(input("请输入一个值"))
        if num < 0:
            num = num*-1
            symbol = -1
        else:
            symbol = 1                   #记录num的符号，并去掉符号往下运行

        if num>2**32-1 or num<-2**32:
            return 0                     #如果超出范围，返回0
        else:
            num = str(num)               #把数字转化为字符串，以便按位操作

        point = len(num)-1               #point指向num的最后一位
        ans = [0 for x in range(0,point+1)]     #创建一个全零列表，之后重新赋值
        for i in num:
            ans[point] = int(i)
            point = point-1              #把字符串倒着赋值给ans列表

        for index in ans:
            if index == 0:
                del ans[ans.index(index)]   #去除前面的0，好像没必要，现在返回值形势为[2,1]

        cap = len(ans) - 1
        a = 0
        for index in ans:
            a = a + index * 10 ** cap
            cap = cap - 1
        return a*symbol                     #把列表按位转化为数字

p = Solution()
print(p.fun())
