
程序如下：

    class Solution:
        def intToRoman(self, num: int) -> str:
            ge = num % 10
            shi = num//10%10
            bai = num//100%10
            qian = num//1000
            str_ge = self.judge(ge,"I","V","X")
            str_shi = self.judge(shi,"X","L","C")
            str_bai = self.judge(bai,"C","D","M")
            str_qian = self.judge(qian,rm1 = "M")
            return str_qian+str_bai+str_shi+str_ge
        def judge(self,num=0,rm1="",rm2="",rm3=""):
            if num<=3:
                return num*rm1
            elif num == 4:
                return rm1+rm2
            elif num<=8:
                return rm2+rm1*(num-5)
            else:
                return rm1+rm3

记录为：
![1567845586(1).jpg](https://pic.leetcode-cn.com/04674137374456a4db9984acd8ebf9c7b8f8c14d8ca4c2617aae70f39392e049-1567845586\(1\).jpg)
