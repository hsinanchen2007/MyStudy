![捕获.PNG](https://pic.leetcode-cn.com/3120231c897a85a27821b7885854151bb898b43974dd5be05a9a3205f69af5a0-%E6%8D%95%E8%8E%B7.PNG)


class Solution:
    def intToRoman(self, num: int) -> str:
        dic = {
            1: "I", 4: "IV", 5: "V", 9: "IX", 10: "X", 40: "XL", 50: "L", 90: "XC", 100:"C", 400: "CD", 
            500: "D", 900: "CM", 1000: "M",}

        res = ""
        # 将key从大到小依次遍历
        for key in sorted(dic.keys())[::-1]:
            # 查找小于num值并且最接近num值的key
            if key <= num:
                n = num // key
                if n > 0:
                    # 字符串复制，如"I"*3 == "III"
                    res += dic[key] * n
                    # 处理剩下的值
                    num = num % key

                    if num == 0:
                        break

        return res