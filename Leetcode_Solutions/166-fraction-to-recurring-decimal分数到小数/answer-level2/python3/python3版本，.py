问题的关键在与如何判断循环小数出现的位置：
建立一个表格记录每一位运算的得数，余数和得数在小数部分的序号。当出现两次相同的得数和余数数，它们所对应的序号便是小数的循环部分。所以我建立了一个二维字典来存储该数据

class Solution:
    def dict2exist(thedict, key_a, key_b): 
        if key_a in thedict:
            if key_b in thedict[key_a]:
                return True
        return False

    def addtodict2(thedict, key_a, key_b, val): 
        if key_a in thedict:
            thedict[key_a].update({key_b: val})
        else:
            thedict.update({key_a:{key_b: val}})    

    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        a = abs(numerator)
        b = abs(denominator)
            
        inter = a//b
        yu = a%b
        listint = [str(inter)]
        if numerator*denominator <0:
            listint.insert(0,'-')
        listxiaoshu = []
        if yu ==0:
            return ''.join(listint)
        data = {}
        i = 0
        while yu!=0:
            i = i+1
            inter = yu*10//b   #某一次得数和产生的余数
            yu = (yu*10)%b
            if Solution.dict2exist(data, inter, yu): 
                listxiaoshu.insert(data[inter][yu]-1,'(')
                listxiaoshu.append(')')
                break
            else:
                listxiaoshu.append(str(inter))
                Solution.addtodict2(data, inter, yu, i)
        listxiaoshu.insert(0,'.')
        return ''.join(listint+listxiaoshu)

        


        

