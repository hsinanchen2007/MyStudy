首先讲一下思路，
1. 要让maxtrix一行相等，只有两种可能,全是0或者全是1
2. 比如说对于matrix的其中一行来讲-[0,1,0]
    在matrix里只有[1,0,1]或者[0,1,0]翻转后可以得到两个相同的行
     [0,1,0]                                                     
     [1,0,1]
      翻转第二列，或者翻转第一，三列
      __所有找到的对应的行，一定是每一位数都相反或者都相同__
      把[1,0,1]全部翻转后就是[0,1,0]
3. 现在思路就很清晰了，我可以遍历matrix把[0，1，0]当成一个key存在字典里对应一个1（因为就一行来讲怎么都可以变成一行一样的，在这里[0,1,0]翻转第二行得到[0,0,0]），当我们在之后的遍历中遇到1开头的行，那么我们把这一行的所有数全部翻转然后存在字典里，遇到已经存过的key就把这个key对应的值加1，代表我们又找到了一行-在翻转后和这个key一样。(这样字典里存的key都是0开头的)
4. 最后遍历字典找到最大值
注意因为List是unhashable，所以我们只能把list全部变成tuple存在字典里
```
class Solution:
    def maxEqualRowsAfterFlips(self, matrix) -> int:
        counter_dic = dict()
        maxCount = 0
        for row in matrix:
            if row[0] == 1:
                tup_row = tuple(1-x for x in row)
            else:
                tup_row = tuple(row)
            # 把tuple_row存在字典里
            if tup_row in counter_dic:
                counter_dic[tup_row] += 1
            else:
                counter_dic[tup_row] = 1
        # 遍历找到最大值
        for count in counter_dic.values():
            maxCount = max(maxCount, count)
        return maxCount
```