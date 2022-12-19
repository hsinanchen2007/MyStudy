class Solution(object):
    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return("Zero")
        list0 = [""," One"," Two"," Three"," Four"," Five"," Six"," Seven"," Eight"," Nine"]
        list10 = ["",""," Twenty"," Thirty"," Forty"," Fifty"," Sixty"," Seventy"," Eighty"," Ninety"]
        list11 = [" Ten"," Eleven"," Twelve"," Thirteen"," Fourteen"," Fifteen"," Sixteen"," Seventeen"," Eighteen"," Nineteen"]
        result = ""
        if num>=pow(10,9):
            result = result + list0[num//pow(10,9)] + " Billion"
            num = num % pow(10,9)
        if num>=pow(10,6):
            temp = num//pow(10,6)
            num = num % pow(10,6)
            result = result + self.getWord(temp) + " Million"
        if num>=pow(10,3):
            temp = num//pow(10,3)
            num = num % pow(10,3)
            result = result + self.getWord(temp) + " Thousand"
        result = result + self.getWord(num)
        if result[0] == ' ':
            result = result[1:]
        return result
        
            
            
            
    def getWord(self,num):
        list0 = [""," One"," Two"," Three"," Four"," Five"," Six"," Seven"," Eight"," Nine"]
        list10 = ["",""," Twenty"," Thirty"," Forty"," Fifty"," Sixty"," Seventy"," Eighty"," Ninety"]
        list11 = [" Ten"," Eleven"," Twelve"," Thirteen"," Fourteen"," Fifteen"," Sixteen"," Seventeen"," Eighteen"," Nineteen"]
        result = ""
        if num>=100:
            result = result + list0[num//100] + " Hundred"
            num = num%100
        if num>=20:
            result = result + list10[num//10]
            num = num%10
        elif 10<=num<20:
            result = result + list11[num-10]
            num = 0
        result = result + list0[num]
        return result

        
        