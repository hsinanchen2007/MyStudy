暴力分解（比较蠢的办法）：
1：先将方程分为左右两个式子
2：然后分别对左右两个式子进行合并同类项，分别放到列表中（未知数和未知数进行相加减，数值和数值进行相加减），最终左边和右边都最多只剩两项
3：将右边的未知数项移到左边，并将此项从右边中删除；将左边式子的数值项移到右边，并将此项从左边中删除
4：最后将左右两边的分类，求解

class Solution(object):
    def solveEquation(self, equ):
        left, right = equ.split("=")  # 将式子分为左右两个
        lef = self.unknow_num(left)   # 左边式子经过化解的最终只剩未知数项和常数项
        rig = self.unknow_num(right)  #右边边式子经过化解的最终只剩未知数项和常数项
        for r in rig:  # 将右边未知数移到左边
            if type(r) == str:
                rx = -int(r.replace("x",""))
                rxr = str(rx) + "x"
                lef.append(rxr)
                rig.remove(r)
        for l in lef:  # 将左边常数项移到右边
            if type(l) == int:
                ln = -l
                rig.append(ln)
                lef.remove(l)
        x_end = self.un_result(lef)  # 计算未知项的结果
        i = 0
        try:  # 分类，算出结果
            for s in rig:
                i = s+i
            if int(x_end.replace("x","")) == 0 and i == 0:
                return "Infinite solutions"
            elif int(x_end.replace("x","")) == 0 and i != 0:
                return "No solution"
            else:
                solutions = i/int(x_end.replace("x",""))
                return "x=%d"%solutions
        except Exception:
            pass
    
    def unknow_num(self,left): 
        “”将式子中包含x项的挑出来，加到uknow列表中“”
        uknow = []
        for nums, i in enumerate(left):
            if i=="x":
                if left[nums-1] in ["+","-"]:
                    uknow.append(left[nums-1:nums+1])
                else:
                    zs = left[:nums].rfind("+")
                    fs = left[:nums].rfind("-")
                    if zs>=0 and fs>=0:
                        if zs>fs:
                            uknow.append(left[zs:nums+1])
                        else:
                            uknow.append(left[fs:nums+1])
                    elif zs == -1 and fs>=0:
                        uknow.append(left[fs:nums+1])
                    elif fs == -1 and zs>=0:
                        uknow.append(left[zs:nums+1])
                    elif zs == -1 and fs == -1:
                        uknow.append(left[:nums+1])
        x_num = self.un_result(uknow)
        z_num = self.know_num(uknow,left)
        end_res = [x_num, z_num]
        return end_res
    
    def un_result(self,uknow):
        “”“算出未知项加减后的结果“””
        num = 0
        try:
            for apt in uknow:
                if apt=="x" or apt == "+x":
                    num = num+1
                elif apt == "-x":
                    num = num-1
                elif apt.replace("x",""):
                    num = num+int(apt.replace("x",""))
        except Exception:
            pass
        f = str(num)+"x"
        return f
    
    def know_num(self,uknow,left):
        “”“算出常数项的结果”“”
        for apt in uknow:
            repo = left.replace(apt,"",1).strip(" ") # repo是式子中去除未知项后的字符串
            left=repo
        repo1 = left.replace("-","+-").split("+")
        su = 0
        for sz in repo1:
            if len(sz)==0:
                continue
            else:
                su = su+int(sz)
        return su

        
    


                    
        
                