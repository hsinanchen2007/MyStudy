python居然全部100了，神奇（其实技术很渣）

做法就是先判断两个和一样不，不一样肯定不行，2 对应两个都是1,0对应两个都是0 1就用up 和low之中较大的先减一 最后完了再判断最后的情况能不能对的上
import copy
class Solution:
    def reconstructMatrix(self, upper: int, lower: int, colsum: List[int]) -> List[List[int]]:
        if sum(colsum)!=upper+lower:
            return []
        up1=[]
        low1=[]
        up2=copy.deepcopy(upper)
        low2=copy.deepcopy(lower)
        for i in colsum:
            if i ==2:
                up1.append(1)
                low1.append(1)
                upper-=1
                lower-=1
            if i ==0:
                up1.append(0)
                low1.append(0)
            if i ==1:
                if upper>=lower:
                     up1.append(1)
                     low1.append(0)
                     upper-=1
                else:
                    up1.append(0)
                    low1.append(1)
                    lower-=1
        # print(up2,low2)            
        if sum(up1)==up2 and sum(low1) ==low2:       
            return [up1,low1] 