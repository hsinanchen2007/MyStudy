*小白刚开始刷题，还请大家给出改进建议*
*方法三 为题解中@Krahets的改进，效果得到了显著提升*
**方法一**
思路：看到题后知道应该用栈的思路求解
因此先写出第一个最简单的方法：
```
        badict={'(':')','{':'}','[':']'}
        s=list(s)
        restore=[]
        for i in range(len(s)):
            if restore==[]:
                if s[i] not in badict.keys():
                    return False
                else:
                    restore.append(s[i])
            else:
                if s[i]==badict.get(restore[-1]):
                    restore.pop()
                else:
                    restore.append(s[i])
        if restore==[]:
            return True
        else:
            return False
```
这个方法就是最常用最简单的栈的思路，因此时间复杂度和空间复杂度也是**居中水平都在50%以上**

**方法二**
对方法一稍加改进
改进思路主要是：如果匹配一定会是偶数个括号，因此可以先判断。若s长度为奇数，则一定是无效
代码如下：
```
        badict={'(':')','{':'}','[':']'}
        s=list(s)
        **if len(s)%2 !=0:
            return False**
        else:
            restore=[]
            for i in range(len(s)):
                if restore==[]:
                    if s[i] not in badict.keys():
                        return False
                    else:
                        restore.append(s[i])
                else:
                    if s[i]==badict.get(restore[-1]):
                        restore.pop()
                    else:
                        restore.append(s[i])
            if restore==[]:
                return True
            else:
                return False
```
改进之后空间复杂度没有太多的变化，但时间复杂度得到了显著降低，**击败了98%的提交结果**

**方法三**
看到题解中大神写了非常简洁的代码，提交了之后发现时间复杂度和空间复杂度之后50%左右，并不是很高
于是对该方法进行改进，代码如下：
```
        dic = {'{': '}',  '[': ']', '(': ')'}
        stack = ['?']
        for c in s:
            if c in dic: stack.append(c)  #只判断是否在key中，即左括号
            elif dic.get(stack.pop())!= c: 
                return False 
        return len(stack) == 1
```
其实改进非常少，主要是使用dict.get()，因此可以修改dic中元素内容。但代码运行的时间复杂度得到显著提升，**击败99%的提交结果**