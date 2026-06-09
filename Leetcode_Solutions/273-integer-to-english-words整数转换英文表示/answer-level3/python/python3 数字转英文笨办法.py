```python
class Solution:
    
    def numberToWords(self, num: int) -> str:
        self.num = num
        
        convertMap = {
            1000000000: 'Billion',
            1000000: 'Million',
            1000: 'Thousand',
            100: 'Hundred',
            90: 'Ninety',
            80: 'Eighty',
            70: 'Seventy',
            60: 'Sixty',
            50: 'Fifty',
            40: 'Forty',
            30: 'Thirty',
            20: 'Twenty',
            19: 'Nineteen',
            18: 'Eighteen',
            17: 'Seventeen',
            16: 'Sixteen',
            15: 'Fifteen',
            14: 'Fourteen',
            13: 'Thirteen',
            12: 'Twelve',
            11: 'Eleven',
            10: 'Ten',
            9: 'Nine',
            8: 'Eight',
            7: 'Seven',
            6: 'Six',
            5: 'Five',
            4: 'Four',
            3: 'Three',
            2: 'Two',
            1: 'One',
            0: 'Zero'
        }
        
        num_list = [
            100, 90, 80, 70, 60, 50, 40, 30, 20, 19, 18, 17, 16,
            15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
        ]
        
        change_name = ''
        new_num = self.num
        
        if new_num != 0:
            for i in [1000000000, 1000000, 1000]:
                if (self.num // i) >= 1:
                    new_num = self.num // i
                    for j in num_list:
                        if j == 100:
                            if (new_num // j) >= 1:
                                change_name = change_name + convertMap[new_num//j] + ' '
                                change_name = change_name + convertMap[j] + ' '
                                new_num = new_num % j
                        else:
                            if new_num == 0:
                                break
                            else:
                                if (new_num // j) >= 1:
                                    change_name = change_name + convertMap[j] + ' '
                                    new_num = new_num % j
                    change_name = change_name + convertMap[i] + ' '
                    self.num = self.num - i*(self.num // i)
                    
            if 1000 > self.num >= 1:
                for j in num_list:
                    if j == 100:
                        if (self.num // j) >= 1:
                            change_name = change_name + convertMap[self.num // j] + ' '
                            change_name = change_name + convertMap[j] + ' '
                            self.num = self.num % j
                    else:
                        if self.num == 0:
                            break
                        elif (self.num // j) >= 1:
                            change_name = change_name + convertMap[j] + ' '
                            self.num = self.num % j
                            
            name_list = change_name.split(' ')
            name_list.pop(-1)
            change_name = ' '.join(name_list)
            
            return change_name
        else:
            change_name += convertMap[new_num]
            return change_name
                            
                        