![image.png](https://pic.leetcode-cn.com/014c32f94045f90c51bda86c83b2af9e30146704da0c7c131654b2fb4a16ba19-image.png)

思路就是挨个比较过去，简单粗暴没啥技巧。

```
class Solution(object):
    def isAlienSorted(self, words, order):
        """
        :type words: List[str]
        :type order: str
        :rtype: bool
        """
        #从前两个开始挨个比过去
        for i in range(len(words)-1):
            #按照字符从第一个向后比过去
            for j in range(len(words[i])):
                #用try处理，当["apple","app"]这种情况时
                #比较到“l”时，由于获取不到"app"的3号位，会进入except。
                try:
                    #当两个词顺序正确，break这个循环，比较后面的两个词
                    if order.index(words[i][j])<order.index(words[i+1][j]):
                        break
                    #当两个词这一字符相等，比较下一字符
                    elif order.index(words[i][j])==order.index(words[i+1][j]):
                        continue
                    #两个词顺序不正确，返回False
                    else:
                        return False
                except:
                    return False
        #比到最后也没有问题，那就返回正确
        return True
```
