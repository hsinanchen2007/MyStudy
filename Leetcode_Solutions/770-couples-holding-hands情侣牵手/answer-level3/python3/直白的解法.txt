问题在于最少
我们不妨考虑一种情况，[0,6,..........,1,5],能做到最少交换在于对(0,6) 和 (1,5)之间只进行一次交换，而不涉及其他人的变动，所以优先考虑此等情况，优先交换，之后按一一迭代找到与当前匹配的情侣交换即可
```
class Solution:
    def __init__(self):
        self.count = 0

    # 获取对象(指交往的人，不是object)的信息
    def get_other(self, num):
        if num % 2 == 0:
            return num + 1
        else:
            return num - 1

    def minSwapsCouples(self, row: List[int]) -> int:
        self.row = row
        # 先对符合一次交换就完成两组匹配的进行交换
        for i in range(0, len(self.row), 2):
            # 对象就在旁边，不需要交换
            if self.row.index(self.get_other(self.row[i])) == i+1:
                continue
            
            i_index = i
            i_name = self.row[i_index]
            i_lover_name = self.get_other(i_name)
            i_lover_index = self.row.index(i_lover_name)

            i_table_index = i+1
            i_table_name = self.row[i_table_index]
            i_table_lover_name = self.get_other(i_table_name)
            # i_table_lover_index = self.row.index(i_table_lover_name)

            i_lover_table_index = self.get_other(i_lover_index)
            i_lover_table_name = self.row[i_lover_table_index]

            # 比较同桌的对象和对象的同桌是否是同一个人，是的话进行一次交换
            if i_table_lover_name == i_lover_table_name:
                self.row[i_lover_index], self.row[i_table_index] = i_table_name, i_lover_name
                self.count += 1

        # 再依次匹配交换
        for i in range(0, len(self.row), 2):
            # 对象就在旁边，不需要交换
            if self.row.index(self.get_other(self.row[i])) == i+1:
                continue
            i_index = i
            i_name = self.row[i_index]
            i_lover_name = self.get_other(i_name)
            i_lover_index = self.row.index(i_lover_name)

            i_table_index = i+1
            i_table_name = self.row[i_table_index]

            # 找到匹配情侣进行交换
            self.row[i_lover_index], self.row[i_table_index] = i_table_name, i_lover_name
            self.count += 1
            
        return self.count
    
```
时间复杂度O(n)
空间复杂度O(1)
