根据题目要求不断的使用if else 语句
中间有一些小的细节需要好好推敲




class Solution:
    def myAtoi(self, str: str) -> int:
        str=str.lstrip()
        if len(str)==0:  
            return 0
        if not str[0].isdigit() and str[0]!='-' and str[0]!='+':
            return 0
        if str[0]=='-'or str[0]=='+':
            if len(str)==1:
                return 0
            count=1
            
            for s in str[1:]:
                if s.isdigit():
                    count+=1
                else:
                    if count==1:
                        return 0
                    else:
                        num=int(str[:count])
                        if -2**31<=num<=2**31-1:
                            return num
                        elif num > 2**31-1:
                            return 2**31-1
                        else:
                            return -2147483648
            if count==len(str):
                num=int(str)
                if -2**31<=num<=2**31-1:
                    return num
                elif num > 2**31-1:
                    return 2**31-1
                else:
                    return -2147483648
                        
        count=0
        for s in str:
            if s.isdigit():
                count+=1

                    
            else:
                num=int(str[:count])
                if -2**31<=num<=2**31-1:
                    return num
                elif num > 2**31-1:
                    return 2**31-1
                else:
                    return -2147483648
        if count==len(str):
            num=int(str)
            if -2**31<=num<=2**31-1:
                return num
            elif num > 2**31-1:
                return 2**31-1
            else:
                return -2147483648

