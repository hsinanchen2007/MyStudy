## 思路

根据题意，

题目需要不断累加机械手从索引`i`移动到索引`j`所需要的时间`|i - j|`，

因此可以用一个变量`cur_pos`记录机械手当前所在的索引，

然后直接线性扫描`word`中的每一个字母`char`，并在`keyboard`里找到机械手需要移动到的索引，即`char`在`keyboard`里的下标，

再将两个索引之差累加起来即可。

因为可能需要多次查询`keyboard中`元素对应的下标，所以不妨开辟一个哈希表`dic`提前准备好所有对应的结果，

这样每次查询下标的时候就可以直接读取结果，加快程序速度。

## 代码实现

```Python
class Solution(object):
    def calculateTime(self, keyboard, word):
        """
        :type keyboard: str
        :type word: str
        :rtype: int
        """
        dic = dict()
        for i, char in enumerate(keyboard):
            dic[char] = i
            
        res, cur_pos = 0, 0
        for char in word:
            res += abs(dic[char] - cur_pos)
            cur_pos = dic[char]           
        return res


```


## 复杂度分析

时间复杂度： $O(n)$，因为需要线性扫描整个输入的word

空间复杂度： $O(1)$，注意哈希表长度固定为26，跟输入word的长度无关 



 