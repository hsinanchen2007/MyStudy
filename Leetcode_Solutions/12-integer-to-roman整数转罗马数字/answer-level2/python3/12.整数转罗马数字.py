从大到小计算单位基的个数，把数字的单位基重复对应个数相加，返回字符串
```
class Solution:
    def intToRoman(self, num: int) -> str:
        roman_dict = {
            1:'I',
            5:'V',
            10:'X',
            50:'L',
            100:'C',
            500:'D',
            1000:'M',

            4:'IV',
            9:'IX',
            40:'XL',
            90:'XC',
            400:'CD',
            900:'CM'
        }

        if num in roman_dict:
            return roman_dict[num]

        # 基列表
        unit_list = [1000,900,500,400,100,90,50,40,10,9,5,4,1]
        
        unit_num_list = []
        num_str = ''

        for unit in unit_list:
            # 计算基的个数
            unit_num = int(num/unit)
            # 将余数传递给更小的基
            num = num % unit
            # 记录基的个数
            unit_num_list.append(unit_num)
 
        for i in range(len(unit_num_list)):
            num_str += unit_num_list[i] * roman_dict[unit_list[i]]
        
        return num_str
```
