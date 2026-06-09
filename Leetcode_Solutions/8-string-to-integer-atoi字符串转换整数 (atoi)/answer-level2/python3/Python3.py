class Solution:
    def myAtoi(self, s: str) -> int:
        #判断输入的字符串是否为空，或者仅包含空白字符
        if s=='' or s==' ':
            return 0
        #生成两个列表，integer1_list用于判断首个非空字符是否为有效字符
        #integer2_list用于判断当首个非空字符是为有效字符时，下一个字符是否为数字
        integer1_list=['0','1','2','3','4','5','6','7','8','9','-','+']
        integer2_list=['0','1','2','3','4','5','6','7','8','9']
        list_s=list(s)
        list1=[]
        #得到除去空字符的字符串
        for i in range(len(list_s)):
            if list_s[i]==' ':
                continue
            else:
                list_s=list_s[i:]
                break
        #判断除去空字符的字符串的第一个值是否为有效字符
        if list_s[0] not in integer1_list:
            return 0
        else:
            #得到以‘-’开头的有效子字字符串（最终得到负数）
            if list_s[0]=='-':
                for j in range(len(list_s)-1):
                    j=j+1
                    if list_s[j] in integer2_list:
                        continue
                    else:
                        list_s=list_s[:j]
                        break
            #得到有效子字字符串（最终得到正数）
            elif list_s[0]=='+':
                    for j in range(len(list_s)-1):
                        j=j+1
                        if list_s[j] in integer2_list:
                            continue
                        else:
                            list_s=list_s[1:j]
                            break
            else:
                #得到有效子字字符串（最终得到正数）
                for k in range(len(list_s)):
                    if list_s[k] in integer2_list: 
                        continue
                    else:
                        list_s=list_s[:k]
                        break
        #判断得到的子字符串是否有值，以及只有一个值时，是否为有效数字
        if len(list_s)==1:
            if list_s[0] in integer2_list:
                return int(''.join(list_s))
            else:
                return 0
        elif len(list_s)==0:
            return 0
        else:
       #判断将列表元素拼接为新的字符串，再转换拼接字符串为整数得到的值，是否在要求范围内     
            if int(''.join(list_s))<(-2**31):
                return -2**31
            elif int(''.join(list_s))>(2**31-1):
                return 2**31-1
            else:
                return int(''.join(list_s))