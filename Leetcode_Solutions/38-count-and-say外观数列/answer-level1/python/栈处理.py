报数关键在于统计从左到右不同的数字各有几个，如：
        <1>     有1个1        -->   (1/1)   -->    <11>
        <11>    有2个1        -->   (2/1)   -->    <21>
        <21>    有1个2 1个1   -->     (1/2 1/1)      -->   <1211>
        <1211>  有1个1 1个2 2个1  --> (1/1 1/2 2/1)  -->   <111221>
        ...
从左到右先进先出统计数字个数，很自然想到队列处理。
**思路：**
    从左侧遍历原始str，压栈；
    若当前str的字符与栈内字符不相同，出栈清空，更新new_str，并重新入栈，即保证栈内字符相同
    循环结束，出栈清空，更新new_str并迭代原始str
**以<1211>为例：**
    char = 1   不与栈内字符不同,入栈  [1]
    char = 2   与栈内字符不同,出栈清空，跟新new_str='11',重新入栈  [2]
    char = 1   与栈内字符不同,出栈清空，跟新new_str='1112',重新入栈  [1]
    char = 1   与栈内字符相同,入栈  [11]
    循环结束，出栈清空，更新new_str并迭代原始str
**代码：**
```
def countAndSay(n):
    """
    :type n: int
    :rtype: str
    """
    if n < 1:
        return
    res = '1'

    from collections import deque
    queue = deque()

    while n > 1:
        new_res = ''
        for char in res:
            # 遇到不同数值，出栈，清空
            if len(queue) > 0 and char != queue[0]:
                # 几个几
                new_res += (str(len(queue))+queue.popleft())
                queue.clear()
            # 数字相同压栈
            queue.append(char)
        # 出栈，清空
        new_res += (str(len(queue)) + queue.popleft())
        queue.clear()
        res = new_res
        n -= 1

    return res
```
