

    def countSegments(self, s: str) -> int:
        if s=='':
            return 0
        sumw = 1
        k=0
        for i in s:
            if i!=' ':
                k=1
            if k==1 and i==' ':
                sumw+=1
                k=0
        if s[-1]==' ':
            return sumw-1
        else:
            return sumw

本代码的关键在于k变量的使用