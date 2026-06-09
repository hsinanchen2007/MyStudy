```
class Solution:
    def numberToWords(self, num: int) -> str:
        res_words = self.numberToWordsImpl(num)
        if res_words[-1] == ' ':
            res_words = res_words[:-1]
        return res_words

    def numberToWordsImpl(self, num: int) -> str:
        ten = 10
        hundred = 100
        thousand = 1000
        million = 1000000
        billion = 1000000000
        int_words_dict = {1:'One ', 2:'Two ', 3:'Three ', 4:'Four ', 5:'Five ', 6:'Six ', 7:'Seven ', 8:'Eight ', 9:'Nine ',
                          ten:'Ten ', 11:'Eleven ', 12:'Twelve ', 13:'Thirteen ', 14:'Fourteen ', 15:'Fifteen ', 16:'Sixteen ',
                          17:'Seventeen ', 18:'Eighteen ', 19:'Nineteen ', 20:'Twenty ', 30:'Thirty ', 40:'Forty ',
                          50:'Fifty ', 60:'Sixty ', 70:'Seventy ', 80:'Eighty ', 90:'Ninety ', hundred:'Hundred ',
                          thousand:'Thousand ', million:'Million ', billion:'Billion ', 0:'Zero'}
        spacil_list = [hundred, thousand, million, billion]
        english_words = ''
        if num == 0:
            return int_words_dict[num]
        while num > 0:
            if num >= billion:
                num, english_words = self.numberForLowLevel(num, english_words, billion, int_words_dict, spacil_list)
            elif num >= million:
                num, english_words = self.numberForLowLevel(num, english_words, million, int_words_dict, spacil_list)
            elif num >= thousand:
                num, english_words = self.numberForLowLevel(num, english_words, thousand, int_words_dict, spacil_list)
            elif num >= hundred:
                num, english_words = self.numberForLowLevel(num, english_words, hundred, int_words_dict, spacil_list)
            else:
                if num in int_words_dict:
                    english_words += int_words_dict[num]
                    num -= num
                else:
                    count = num // ten
                    english_words += int_words_dict[count * ten]
                    num = num - (count * ten)
        return english_words

    def numberForLowLevel(self, num: int, res: str, level: int, int_words_dict: {}, spacil_list: list) -> (int, str):
        count = num // level
        if count in int_words_dict:                        #在字典中直接查询转换
            if count in spacil_list:                       #整100， 1000， 1000000， 1000000000 要带One
                res += int_words_dict[1]
                res += int_words_dict[count]
            else:                                          #非整100， 1000， 1000000， 1000000000 直接找
                res += int_words_dict[count]
        else:
            res += self.numberToWordsImpl(count)           #不在字典中递归转换count
        res += int_words_dict[level]                       #别忘记带上 level 的单位
        num = num - (count * level)
        return num, res
```



