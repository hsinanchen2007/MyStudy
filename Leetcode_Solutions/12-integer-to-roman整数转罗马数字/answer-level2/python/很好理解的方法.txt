    def intToRoman(self, num: int) -> str:
        introman={0:'',1:'I',5:'V',10:'X',50:'L',100:'C',500:'D',1000:'M',4:'IV',9:'IX',40:'XL',90:'XC',400:'CD',900:'CM'}
        num=str(num)
        res=''
        for i,numi in enumerate(num[::-1]):
            numi=int(numi)*(10**i)
            numiroman=introman.get(numi,False)
            if numiroman or numiroman=='':
                res=numiroman+res
            else:
                numiroman=numi//(10**i*5)*introman.get(10**i*5,'')+int(numi%(10**i*5)/(10**i))*introman[10**i]
                res=numiroman+res
        return res