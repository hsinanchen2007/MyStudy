创建一个空列表，循环判断列表中数值是奇数还是偶数，如果是奇数放在列表末尾，如果是偶数把它插入到列表第一位
```
class Solution(object):
    def sortArrayByParity(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        list1 = []
        for i in A:
            if i%2 ==0:
                list1.insert(0,i)
            else:
                list1.append(i)
        return list1
```
