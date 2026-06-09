    def myAtoi(self, str: str) -> int:
        k=0
        for i in str:
            if i!=' ':
                break
            k+=1
        str=str[k:] #去掉前面的空格

        try:
            if str[0] in ['+','-'] and str[1] in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']:
                fuhao=str[0]
                str=str[1:]
                pass
            elif str[0] in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']:
                fuhao=''
                pass
            else:
                return 0
        except:
            return 0

        res=''
        for i in str:
            if i in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']:
                res+=i
            else:
                break
        res=fuhao+res

        if int(res)>2**31-1:
            return 2**31-1
        elif int(res)<-2**31:
            return -2**31
        else:
            return int(res)