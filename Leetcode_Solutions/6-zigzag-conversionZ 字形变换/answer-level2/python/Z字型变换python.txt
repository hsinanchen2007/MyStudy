这一题官方给的解题方法是按行排序和按行访问两种方法，好肯定是很好的，但我还是想先把我第一次的方法给贴出来，因为我觉得这个可能对我们这些菜鸟会更容易接受些（大神绕道）

方法一：得出Z字型矩阵

这个方法就很直接了，题目不是要我们求出一个字符串Z字型变换嘛，那我们就先把它的Z字型矩阵求出来，再依次按行读取相应元素即可得出最终答案，是不是很简单。

代码如下：
```python
class Solution:
def convert(self, s, numRows):
        if numRows <= 1:
            return s
        DecArray = self.getArray(s, numRows)
        result = ''.join(DecArray.flatten())
        result = result.replace('-', '')
        return result

# 构建Z型数组法获得相关数组
def getArray(self, s, numRows):
        DecArray = np.array([['-'] * len(s)] * numRows)
        ArrayIndex = 0
        IndexCol = 0
        while ArrayIndex < len(s):
            if IndexCol % (numRows - 1) == 0:
                line = ArrayIndex - (2 * numRows - 2) * int(IndexCol / (numRows - 1))
                if line < numRows:
                    DecArray[line][IndexCol] = s[ArrayIndex]
                else:
                    IndexCol += 1
                    ArrayIndex -= 1
            else:
                sum = int(IndexCol / (numRows - 1) + 1) * (numRows - 1)
                line = sum - IndexCol
                DecArray[line][IndexCol] = s[ArrayIndex]
                IndexCol += 1
            ArrayIndex += 1
        return DecArray
```
但是这个最简单的方法的执行效率也真是不咋地，硬是没跑出来，报了超出时间限制的错误。当时确实是对我有些打击，觉得没有哪块地方要花费很长时间，想来想去最后用了官方给的方法才得出答案，还是有些不爽的。

方法二：按行排序法
方法一之所以超出时间限制了，是由于在构建Z型数组部分花费太多时间了。如果我们不去想着先构建Z型数组，那是不是可以节约大把时间呢？答案是肯定的，只要掌握规律，我们就可以很迅速的拿到Z型数组的数据，具体可见下图：

![qq_pic_merged_1557456078400.jpg](https://pic.leetcode-cn.com/06dcc92e78f9c18893194740c1e90153c743d3ea4bb6fbdb305080d070bc7250-qq_pic_merged_1557456078400.jpg)
代码如下：
```python
class Solution:
    def convert(self, s, numRows):
        if numRows <= 1:
            return s
        DecDict = self.getArray(s, numRows)
        rows = min(len(s), numRows)
        ListStr = []
        for line in range(rows):
            ListStr.extend(DecDict[line])
        return ''.join(ListStr)

    # 按行排序法获得相关数组
    def getArray(self, s, numRows):
        rows = min(len(s), numRows)
        DecDict = {}
        for row in range(rows):
            DecDict[row] = []
        curRow = 0
        goingDown = False
        for index in range(len(s)):
            DecDict[curRow].extend(s[index])
            if curRow == 0 or curRow == numRows - 1:
                goingDown = not goingDown
            curRow += 1 if goingDown else -1
        return DecDict
```
这个的执行效率就好多了！
