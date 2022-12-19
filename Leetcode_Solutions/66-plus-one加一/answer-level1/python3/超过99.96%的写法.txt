```
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        temp, ret, flag = [], [], 1
        for i in digits[::-1]:
            if flag == 1:
                temp.append(i + 1)
                flag = 0
                tempInt = temp.pop()
                if tempInt == 10:
                    flag = 1
                    temp.append(0)
                else:
                    temp.append(tempInt)
            else:
                temp.append(i)
        if flag == 1:
            temp.append(1)
            flag = 0
        ret = list(reversed(temp))
        return ret

```

利用列表操作方法，快速实现目标
效果：

![capture_20191125092459600.bmp](https://pic.leetcode-cn.com/3c8dc576a951066c30f5ed90293dd9181956292acc59f245f9a3c3fca03efa7a-capture_20191125092459600.bmp)

