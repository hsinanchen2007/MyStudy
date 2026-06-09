    def letterCombinations(self, digits: str) -> List[str]:
        num2letter={}
        num2letter['2']='abc'
        num2letter['3']='def'
        num2letter['4']='ghi'
        num2letter['5']='jkl'
        num2letter['6']='mno'
        num2letter['7']='pqrs'
        num2letter['8']='tuv'
        num2letter['9']='wxyz'

        if digits=='':
            return ''
        if len(digits)==1:
            return list(num2letter[digits])

        k=0
        a=num2letter[digits[0]]
        b=num2letter[digits[1]]

        while k<=len(digits)-2:
            res=[]
            for i in a:
                for j in b:
                    res+=[i+j]

            try:
                a=list.copy(res)
                b=num2letter[digits[k+2]]
                k+=1
            except:
                break

        return res