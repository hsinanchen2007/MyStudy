有序字典，查找边界‘要转罗马数字’的数字，递归	

 	from collections import OrderedDict

	mapping = OrderedDict({
	    1000: 'M',
	    900: 'CM',
	    500: 'D',
	    400: 'CD',
	    100: 'C',
	    90: 'XC',
	    50: 'L',
	    40: 'XL',
	    10: 'X',
	    9: 'IX',
	    5: 'V',
	    4: 'IV',
	    1: 'I',
	})


	class Solution:
	    def intToRoman(self, num: int) -> str:
	        assert num >= 0, 'num must be natural number'
	        assert num < 4000, 'num must be less than 4000'
	
	        for k, v in mapping.items():
	            if num >= k:
	                return num // k * v + self.intToRoman(num % k)
	        return ''

 上述 for循环 相当于

        # if num >= 1000:
        #     return num // 1000 * mapping[1000] + self.intToRoman(num % 1000)
        # elif num >= 900:
        #     return mapping[900] + self.intToRoman(num - 900)
        # elif num >= 500:
        #     return mapping[500] + self.intToRoman(num - 500)
        # elif num >= 400:
        #     return mapping[400] + self.intToRoman(num - 400)
        # elif num >= 100:
        #     return num // 100 * mapping[100] + self.intToRoman(num % 100)
        # elif num >= 90:
        #     return mapping[90] + self.intToRoman(num - 90)
        # elif num >= 50:
        #     return mapping[50] + self.intToRoman(num - 50)
        # elif num >= 40:
        #     return mapping[40] + self.intToRoman(num - 40)
        # elif num >= 10:
        #     return num // 10 * mapping[10] + self.intToRoman(num % 10)
        # elif num >= 9:
        #     return mapping[9] + self.intToRoman(num - 9)
        # elif num >= 5:
        #     return mapping[5] + self.intToRoman(num - 5)
        # elif num >= 4:
        #     return mapping[4] + self.intToRoman(num - 4)
        # elif num >= 1:
        #     return num // 1 * mapping[1] + self.intToRoman(num % 1)
        # elif num == 0:
        #     return ''
        # else:
        #     pass
