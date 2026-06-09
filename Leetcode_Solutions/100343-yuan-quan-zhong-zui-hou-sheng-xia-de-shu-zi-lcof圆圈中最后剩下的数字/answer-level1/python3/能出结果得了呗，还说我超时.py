```python
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        my_list = list(range(n))
        
        del_list = []  # 所有被删除的元素

        index = 0  # 记录my_list的下标
        count = 1  # 从1数到m
        while True:
            if len(del_list) == len(my_list)-1:
                # 说明就剩1个了
                break
            
            if index == len(my_list):
                # 已经到最后一个了，从头开始循环
                index = 0

            if count > m:
                # 数到m了，重新开始数
                count = 1
            
            # 如果下标对应的元素已经在删除列表中，不计数
            if my_list[index] in del_list:
                count += 0
            elif count == m:
                # 数到m了，删掉这个元素
                count += 1
                del_list.append(my_list[index])
            elif count != m:
                # 否则接着往后数
                count += 1

            # 下标加一
            index += 1
        
        # 输出不存在于del_list的那一个元素
        for i in my_list:
            if i not in del_list:
                return i
```