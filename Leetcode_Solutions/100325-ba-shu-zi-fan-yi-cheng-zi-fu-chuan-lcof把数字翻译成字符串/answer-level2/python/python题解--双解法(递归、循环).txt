### 递归解法(回溯)
![image.png](https://pic.leetcode-cn.com/f7353c62811db12c3b7e422e1f12ea509e7a6c91974be473813fc5ea05bd5ca9-image.png)


- 先看题目中的例子`'12258'`,我们需要求的是有多少种不同的翻译方法,先面的图写一下切分的过程,我们要求`'12258'`总的翻译次数,可以分成求`'2258'`和`'258'`这两个子串的翻译次数之和
- 求`'2258'`时,没有什么需要注意的,因为它前面的一个数字`2`
- 当求`'258'`时,我们需要注意下前面的两个数字是否的范围是否在`10`到`25`之内,如果不在的话,那么就和前面是一个数字的情况是一样的.这里举个例子:当我们求`90349`时,可以分成`9349`和`349`,注意此时`349`前面的`90`已经超出了范围
- 递归方程:`f(i) = f(i+1) + g(i,i+1)*f(i+2)`其中`i`代表当前下标,`g(i,i+1)`代表了坐标`i`和`i+1`所指向的数字所组成的两位数,如果这个两位数在10到25之间那么`g(i,i+1) = 1`,否则`g(i,i+1) = 0`
![image.png](https://pic.leetcode-cn.com/021745152e5c10cd834a59975e6d8551d91ec7dd4456e9ffa535f373bebc270a-image.png)

### 代码

```python
class Solution(object):
    def translateNum(self, num):
        """
        :type num: int
        :rtype: int
        """
        string = str(num)
        length = len(string) - 1
        def Count_sum(string, i, length):
            if i >= length:
                return 1
            if i <= length -1:
                converted = int(string[i]) * 10 + int(string[i+1])
                if converted >= 10 and converted <= 25:
                    return Count_sum(string, i+1, length) + Count_sum(string, i+2, length)
                else:
                    return Count_sum(string, i+1, length)
        
        return Count_sum(string, 0, length)

        
```
### 循环解法(DP)
![image.png](https://pic.leetcode-cn.com/6fe89c7a5992fcf3ce2e8290605126ffd214c8b9405963da5360901763c16a7d-image.png)
- 我们可以从上面的图中看出来,当进行递归运算的时候有很多重复的子问题出现,这就造成了时间上的浪费,对于这种我们便不难想到用DP来解决
- DP一般的就是使用for循环来写,需要创建一个辅助的数组来存储第i个串的最大翻译次数
- 根据转移方程:`f(i) = f(i+1) + g(i,i+1)*f(i+2)`,可知f(length-1) = 1,我们从字符串的倒数第二个开始统计
### 代码
```
class Solution(object):
    def translateNum(self, num):
        """
        :type num: int
        :rtype: int
        """
        string = str(num)
        length = len(string)
        counts = [0] * length
        counts[length-1] = 1
        for i in reversed(range(length-1)):
            counts[i] = counts[i+1]
            converted = int(string[i]) * 10 + int(string[i+1])
            if converted >= 10 and converted <= 25:
                if i < length-2:
                    counts[i] += counts[i+2]
                else:
                    counts[i] += 1
        return counts[0]
```
