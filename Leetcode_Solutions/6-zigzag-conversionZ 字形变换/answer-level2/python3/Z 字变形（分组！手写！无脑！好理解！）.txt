## 直接看图！ 
![1731665440.jpg](https://pic.leetcode-cn.com/19ec6d4810b725eaa82671e3305507d9fe551167793de10ec368e7047c5214d2-1731665440.jpg)

## 思路第一步：分组
1. 我们把传入的字符串进行**分组**， 每个框内的字母为1组；
2. **我们发现**每个相同颜色的框内的一组字母的特点是在传入的字符串中是**连续的**；
3. **我们还发现**每组字母的个数是由**numRow**来确定的；个数为(numRow + numRow - 2);
4. 所以我们把字符串按照**步长**切分成一组一组的，然后按照索引去查找；

## 分组实现过程：
index = 0
lst = []
step = numRow + numRow - 2
 while index < len(s):
            end = index + step
            temp = s[index:end]
            lst.append(temp)
这样我们可以得到lst这个列表的每个元素都是一个组：
lst  ： ['ABCDEF', 'GHIJKM', 'NOPQ']  
最后一组只有四个元素，但是不影响，后面我们可以通过**异常处理**来解决；

## 思路第二步：按照规则取值
1. 可以看出来，**numRow行的第一行**我们只需要取到每组的第一个值就可以了；
2. 但是如果是**numRow行的第2行到num_Row-1行**我们每组要取两个数字，分别是第i=1（i从0开始）个和每组字母个数减去i的那一个；在第一组中就是i=1，B和i = 2 * numRow - 2 - i, F 这两个；
3. 我们还需要考虑最后一组如果用索引去取**取不到会报错**的情况，我们去捕获异常，如果捕获到了就压制它；
## 取值实现过程：
        i = 0
        while i < numRows:  # 取numRow次，每次取1 ~ 2个
            for value in lst:  # 遍历每组， 每组都取
                if 1 <= i <= numRows-2:  # 如果索引是1到numRows-2，每组需要取两个
                    try:  # 这里考虑到最后一组可能会出现取不到报 IndexError
                        final += value[i]
                        final += value[2*numRows-2-i]
                    except: # 捕获到就压制他
                        pass
                else:
                    try:  #  同样，取第numRow行的值最后一组也可能取不到
                        final += value[i]
                    except:  # 压制
                        pass
## 两段核心代码如果理解了，再看我的整个程序就会变得异常的舒服！
```python3
class Solution:
    def convert(self, s: str, numRows: int):
        index = 0
        step = 2*numRows - 2
        lst = []
        final = ""  # 存放最终要返回的结果
        i = 0
        while index < len(s):   #  核心代码1； 分组
            end = index + step
            temp = s[index:end]
            lst.append(temp)
            index = end
        print(lst)
        while i < numRows:  # 核心代码2； 取值
            for value in lst:
                if 1 <= i <= numRows-2:  
                    try:
                        final += value[i]
                        final += value[2*numRows-2-i]
                    except:
                        pass
                else:
                    try:
                        final += value[i]
                    except:
                        pass
            i += 1
        return final
```

##### 刚刚接触python不久！如果觉得能有所帮助的话，可以关注一下我的csdn博客（csdn博客：叫我明同学），也可以加一下我的python学习交流群：625988679 ；本人最近也是在准备考研，您的关注和支持可以无形之中增加我在复试中的表现，谢谢您！


