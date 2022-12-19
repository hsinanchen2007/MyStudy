我们可以利用字符串把它倒过来然后再比较是否溢出

def inversion(num):
    onOff = True
    if num >= 0:
        strNum = str(num)
    else:
        strNum = str(0 - num)
        onOff = False
    if onOff:
        newNum = int(strNum[::-1])
    else:
        newNum = 0 - int(strNum[::-1])
    if (newNum > (2**31)-1) or (newNum < -2**31):
        newNum = 0
    print(newNum)
inversion(123)