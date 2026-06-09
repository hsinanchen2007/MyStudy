
```
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        num = ''  #空字符串保留数字
        res = []  
        for i in digits: #从头遍历一次数组，将数字拼接为字符串
            num = num + str(i) #注意这里也要将遍历元素i强转字符串，因为数组中的元素均为数字
        num = int(num)  
        num += 1
        num = str(num)
        for i in num: #遍历字符串，将字符串转存为数组
            res.append(i)
        return res
```

其实这种方法在某种层面来说有违题意，因为题意目的在于手动进位，这个方法只是一种解决思路而已。
从手动进位的方法来说，其他解答中也提到了倒序遍历，在此就不赘述。