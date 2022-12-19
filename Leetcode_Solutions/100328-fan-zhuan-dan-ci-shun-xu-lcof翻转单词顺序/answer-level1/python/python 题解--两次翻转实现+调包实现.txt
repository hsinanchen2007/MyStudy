### 1.翻转两次(剑指offer)
![image.png](https://pic.leetcode-cn.com/908182c6c9687a47303d3efe1397916b93f957e55fd64709e288e17afb9a50b9-image.png)
- **首先说下,虽然这个方法虽然比直接调用python库函数要花费的时间多,而且代码量也要大,但我个人觉得面试官是想看到我们运用算法和理解算法的基础能力,而不仅仅是调包,所以一些核心的算法东西我们不要使用包,而是能够写出来,仅个人观点,欢迎喷!!**
- 下面介绍算法:
- 上例子:
![image.png](https://pic.leetcode-cn.com/a42331178afad51786c9d86a2eb2b9c6a554c4cda53c32955de82345fa7313a1-image.png)
- 算法分为两部,在之前我们先将原字符前后的空格去除掉,变为`s = "hello world!"`
1. 将`s`整体进行翻转,变为`!dlrow olleh`
2. 然后我们将`s`中的每个单词进行翻转,这里需要注意的是,最终的结果中每个单词之间只有一个空格,且这个字符串前后也没有空格,这里需要进行细节处理,最终为`"world! hello"`
- 代码中有注释可以方便理解

### 代码

```python
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = s.strip()
        s = list(s)
        if not s:
            return ''
        def revers(start, end):#字符串翻转函数
            low = start
            high = end
            while start < end:
                s[start], s[end] = s[end], s[start]
                start += 1
                end -= 1
            return (''.join(s[low:high+1])) + ' '
        
        length = len(s)
        revers(0, length-1)
        start = 0
        end = 0
        result = ''
        while end <= length:
            if s[start] == ' ':
                start += 1
                end += 1
            elif end == length or s[end] == ' ':
                print(start,end)
                temp = revers(start, end-1)#每次返回的是一个单词进行翻转完之后的结果,并且后面带有一个空格
                result = ''.join([result,temp])#将结果连接在一起
                start = end+1
                end += 1
            else:
                end += 1
        return result[:-1]#因为最后有一个空格,所以要去除掉


```
### 2.使用函数
![image.png](https://pic.leetcode-cn.com/34ea537f6434b11293a76bbbc33ec2dd4b7f8ab1240924483295376fd3a08e50-image.png)

- 使用`spilt`函数将原始字符串分离成单个的单词
- 接着将这些单个的单词自行顺序的翻转,再用空格连接起来就可以了

### 代码
```
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        return " ".join(s.split()[::-1])
```
