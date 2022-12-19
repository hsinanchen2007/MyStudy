    def numberToWords(self, num: int) -> str:
        e1 = ['','One','Two','Three','Four','Five','Six','Seven','Eight','Nine']
        e2 = ['Ten','Eleven','Twelve','Thirteen','Fourteen','Fifteen','Sixteen','Seventeen','Eighteen','Nineteen']
        e3 = ['0','0','Twenty','Thirty','Forty','Fifty','Sixty','Seventy','Eighty','Ninety']
        if num==0:
            return 'Zero'
            
        def say_ABC(s):#单独输出三位数字的英文
            a,b,c = s//100,(s//10)%10,s%10
            if a==0: 
                if b==0: return e1[c]
                if b==1: return e2[c]
                if b>1:
                    if c==0: return e3[b]
                    if c!=0: return e3[b] +' '+e1[c]
            if a!=0: 
                s = e1[a] + ' ' +'Hundred'
                if b==0: return s + ' ' + e1[c]
                if b==1: return s + ' ' + e2[c]
                if b>1:
                    if c==0: return s + ' ' + e3[b]
                    if c!=0: return s + ' ' + e3[b] +' '+e1[c]
        
        s = list(str(num))
        t = []#用来保存分割出来的三个数字
        while s!=[]:
            j = 0
            n = 0
            while j<3 and s!=[]:
                n = n + int(s.pop())*(10**j)
                j += 1
            t.append(n)
        
        t2 = []#用来保存每三个数字的英文输出
        e4 = ['','Thousand','Million','Billion']
        for i in range(len(t)):
            s = say_ABC(t[i])
            if s!='':
                if s[-1]==' ':
                    s = s[:-1]
            if i==0 or s=='':
                t2.append(s)
            else:
                t2.append(s+' '+e4[i])
        
        s = ''
        while t2!=[]:#结合
            f = t2.pop()
            s += f
            if t2!=[]:
                if t2[-1]!='':
                    s += ' '
        return s
            
            
        
                