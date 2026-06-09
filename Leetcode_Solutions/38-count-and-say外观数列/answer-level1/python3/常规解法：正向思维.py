通过对前一次结果进行个数统计得到下一次结果，类似数数
![通过.png](https://pic.leetcode-cn.com/cd78d0e766c644daa12cb577861f44a9fc1f8816c04b69a41e9f0763da9469d3-%E9%80%9A%E8%BF%87.png)


代码：

    class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        elif n == 2:
            return "11"
        else:
            pre_num = "11"
            i = 2
            next_num = ""
            while i < n:
                next_num = ""
                temp = pre_num[0]
                # print('temp = ', end='')
                # print(temp)
                count = 1
                j = 0
                while j < len(pre_num):
                    if j == len(pre_num)-1:
                        next_num = next_num + str(count)
                        next_num = next_num + temp
                    elif pre_num[j+1] != temp:
                        next_num = next_num + str(count)
                        next_num = next_num + temp
                        temp = pre_num[j+1]
                        count = 1
                    else:
                        count += 1
                    j += 1
                pre_num = next_num
                i += 1
            return next_num