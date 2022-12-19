![2020-03-21 18-04-36 的屏幕截图.png](https://pic.leetcode-cn.com/060715fdbc36897ac2ccd43e9a04683e022d8fbcf9f3f72f97153b5626758275-2020-03-21%2018-04-36%20%E7%9A%84%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

![2020-03-21 15-06-42 的屏幕截图.png](https://pic.leetcode-cn.com/d681957c5fe68e94c54f5583a656723edc3e5853438145b021a05c17b693e271-2020-03-21%2015-06-42%20%E7%9A%84%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

直观上看，对于给定的x,y我们能利用的信息就这两个，从一个桶倒入另一个桶。
其实不然，如果两个桶的容量不一样，那么我们还是可以利用他们的容量差值信息的。我们以其中的一个测试用例作为例子，x=34,y=5,z=6：
1. 我们可以把容量为34L的桶装满，然后分6次倒入容量为5L的桶内，此时大桶还剩4L水，接着在大桶上刻下标记，记住4L水所在的水位线，最后清空大桶。
2. 把容量为5L的桶装满倒入大桶内使水位刚好达到刚才4L的水位线，则小桶内还剩1L水，记下此时1L水的水位线。
3. 目标是6L，此时再用小桶分2次倒入大桶内1L水即可完成任务。

由以上分析可知，我们可以通过划线的方法才增加可利用信息，这就和曹冲称象的原理很像。
对于输入的x、y我们就要通过求mod的方式找到它们的余数r来作为额外信息，如果在求余数的过程中出现了，
z mod r = 0，这就说明可以通过这个多次添加r倍的水来完成任务。
如果在求余数的过程中一直没有找到合适的余数r来完成任务直到r=0，则说明不能完成任务。

对于解题，我们还是首先把边界条件写出来，对于那些易判断的情况直接判定是否能完成任务。
下边是我的解法：
```
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        if z==0:return True
        if x+y<z:return False
        if x+y==z:return True
        if x==z or y==z:return True
        if x==y:return False
        minNum=min(x, y)
        maxNum=max(x,y)
        while True:
            if minNum==0 or z%minNum==0:
                break
            temp = minNum
            minNum = maxNum%minNum
            maxNum = temp

        return False if minNum==0 else True
```


