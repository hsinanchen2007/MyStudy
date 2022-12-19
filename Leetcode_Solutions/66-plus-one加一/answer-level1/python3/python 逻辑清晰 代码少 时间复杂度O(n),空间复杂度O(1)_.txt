![1575007311(1).jpg](https://pic.leetcode-cn.com/a2376211fb238937e7f26c057beb2bbc53c51b88572836626efbb3aa0b57c2f2-1575007311\(1\).jpg)

# 先看带代码，后分析：
    class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        cur = -1
        while digits[cur] +1 == 10:
            digits[cur] = 0
            cur -= 1
            if cur<-len(digits):
                li = [1]
                return li+digits
        digits[cur] +=1
        return digits
# 捋逻辑：
1，定义一个指针cur，从后往前，按照索引，挨个看每个位置的数字加1的结果，满足条件，digits[cur]=0,cur-1判断指针移到下一个位置的情况;不满足条件，直接跳出循环，在原索引位置加1，返回结果。
2，遇到特殊情况如输入是[9]时，这时digits[-1]=0,但是指针移到了下一个位置，**此时索引已经超出**，所以我们需要再加一个判断，如果超出列表索引，我们可以知道，一定是在最高位，逢十进一了，所以创建一个新li=[1]与此时的digits列表相加,结果返回li+digits即可。