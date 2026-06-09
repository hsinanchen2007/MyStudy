主要思想是先观察IP地址的特点：
1. 由4部分组成，每部分长度为1-3。所以总长度在4-12之间
2. 每部分数字大小在0-255之间
3. 每段数字不能出现"0X"或"00X"的情况，X是一个0-9的数字
4.假设四段长度分别为a,b,c,d，则a+b+c+d=总长度(这不废话嘛)。且1<=a<=3,1<=b<=3,1<=c<=3,1<=d<=3。

好了，开始分解问题：
1. 将输入的数字串根据上述特点分段。如果不符合上述特点的直接返回[]。
2.对符合上述特点的进行保存，最后整体输出。

最后上代码（哈哈哈，4个for，看着虽然有点难受，速度还是可以的）

class Solution():
    def method(self, string):
        if string == "":
            return ""
        elif len(string) < 4 or len(string) > 12:
            return []
        length = len(string)
        possible = []
        for a in range(1,4):
            for b in range(1,4):
                for c in range(1,4):
                    for d in range(1,4):
                        if a+b+c+d == length:
                            splited = [string[0:a],string[a:a+b],string[a+b:a+b+c],string[a+b+c:a+b+c+d]]
                            add = True
                            for each in splited:
                                if   len(each) > 1 and each[0] == '0':
                                    add = False
                                elif int(each)>255 or int(each) < 0:
                                    add = False
                            if add:
                                possible.append(".".join(splited))
        return possible