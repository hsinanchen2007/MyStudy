用时4ms，击败100%

```
class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        res_list = []
        for row_num in range(1, numRows+1):
            temp_list = []
            for i in range(0, row_num):
                if i == 0:
                    temp_list.append(1)
                elif i == row_num -1:
                    temp_list.append(1)
                else:
                    temp_list.append(res_list[row_num-2][i-1] + res_list[row_num-2][i])
            # print(temp_list)
            res_list.append(temp_list)
        return res_list
```
