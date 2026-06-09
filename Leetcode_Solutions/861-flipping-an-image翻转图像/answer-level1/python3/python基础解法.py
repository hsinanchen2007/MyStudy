解题思路：首先遍历list，做列表翻转，然后求1-i。
代码：
class Solution:
    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        list1 = list()
        for i in A:
            list1.append([1-i for i in i[::-1]])
        return list1