我这里将digits列表给反转了来求，这样更好求解。
遍历a，如果该位是9，令其为0.如果数组全由9组成，在末尾加1.反转a得到结果。
class Solution(object):
    def plusOne(self, digits):
        a=digits[::-1]
        for i,j in enumerate(a):
            if j+1==10:
                a[i]=0
                if i+1==len(a):
                    a.append(1)
                    break
            else: 
                a[i]+=1
                break
        return a[::-1]