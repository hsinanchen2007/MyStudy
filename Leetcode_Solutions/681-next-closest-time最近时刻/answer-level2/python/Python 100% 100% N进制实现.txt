分析题目其实就是找到未来和现在最近的那个时间，然后可以想到，如果我组成的那个时间比现在的时间早，那么就是明天的时间了。
所以如果有组成的时间比现在时间大的，而且有效的，那么就肯定拿比这个时间大，而且有效的最小的时间。
                            19:34      19:39    19:41 ..... 这里19.39就是比这个时间更大的第一个时间。
但是如果没有比现在时间更大的时间的话， 就需要找到，比这个时间小的，而且有效的最小的时间，也就是
11:11                       19:34
在这个情况下，比19:34小的最小的时间，就是11:11

然后不难想到这就是一个数学的进位问题，如果这个时间是循环的，就是找到比它大的下一个时间。这里就是19:39中，最大的是19:49，下一个就成了进位一天，时间变成11:11.
然后如果我们能把 1934做一个数学的简化，从大小上可以排序是 1 3 4 9，分别用 0 1 2 3 来替换 1 3 4 9 
就可以变成 0 3 1 2 ，相当于是把时间数字话了，而且这个数字是一个4进制的。
number digit
0 ------ 1 
1 ------ 3
2 ------ 4 
3 ------ 9 
为什么说是4进制呢，因为 1934(0312) 下一个比他大的就是 1939(0313) 下一个就是 1941(0320)所以就是四进制了。
但是进制会随着时间中的不同字符的数量变化，因为当我们出现11:23的时候，这就是一个三进制了。11:13的时候就是一个二进制了，其中不同的字符数量越多，进制越高。
下面的代码就是把时间封装成了对象，其中add函数就是找到下一个时间，而is_valid函数是为了找到这个时间是不是符合 24小时制的计数方式。

如果实现四进制的话，我就用的蠢方法。
但是主函数还是可以看出逻辑的，如果下一个时间不符合进制计数方式，那么就再下一个，直到找到第一个合理的就好了。
然后generate_srting也就是单纯为了返回格式而写的返回函数。

```python
class Time():
    def __init__(self,time):
        time = time[:2] + time[3:]
        self.number_to_digit = sorted(list(set(time)))
        self.promotion = len(self.number_to_digit)
        self.digit_to_number = {self.number_to_digit[i]:i for i in range(self.promotion)}
        self.number_array = [self.digit_to_number[i] for i in time]
        
    def add(self):
        for index in range(3,-1,-1):
            self.number_array[index] += 1
            if self.number_array[index] == self.promotion:
                self.number_array[index] = 0
            else:
                break
        
    def is_valid(self):
        hour = int(self.number_to_digit[self.number_array[0]]) * 10 + int(self.number_to_digit[self.number_array[1]])
        if hour >= 24:
            return False
        minute = int(self.number_to_digit[self.number_array[2]]) * 10 + int(self.number_to_digit[self.number_array[3]])
        if minute >= 60:
            return False
        return True
    
    def generate_string(self):
        hour = self.number_to_digit[self.number_array[0]] + self.number_to_digit[self.number_array[1]]
        minute = self.number_to_digit[self.number_array[2]] + self.number_to_digit[self.number_array[3]]
        return hour + ":" + minute
         
class Solution(object):
    def nextClosestTime(self, time):
        """
        :type time: str
        :rtype: str
        """
        time = Time(time)
        time.add()
        while not time.is_valid():
            time.add()
        return time.generate_string()
                
```