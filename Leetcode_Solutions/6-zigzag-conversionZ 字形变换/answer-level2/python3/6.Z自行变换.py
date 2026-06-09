
暴力法————通过计算z型二维数组，得到最终结果。

```python []
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        result = []
        length_s = len(s)        
        if length_s <= 1 or numRows == 1:
            return s
        else: 
            period_column = numRows-1
            period_letter_num = 2*numRows - 2
            (period_num, add_letter) = divmod(length_s, period_letter_num)
            if add_letter < numRows:
                add_column = add_letter
            else:
                add_column = add_letter % numRows + 1
            numColumns = period_column * period_num + add_column

            letter_mat = [[''for _ in range(numColumns)] for _ in range(numRows)]

            for i in range(numColumns):

                    if i % period_column == 0:
                        for j in range(numRows):
                            if len(s)>0:
                                letter_mat[j][i] = s[0]
                            else:
                                letter_mat[j][i] = ''
                            s = s[1::]
                    elif i % period_column != 0 :
                        if len(s)>0:
                            letter_mat[numRows-1-(i % period_column)][i] = s[0]
                        s = s[1::]

            for j in range(numRows):
                for i in range(numColumns):
                    result.append(letter_mat[j][i])

            result = ''.join(result)
            return result

```


