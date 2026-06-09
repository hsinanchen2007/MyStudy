根据二进制短除法的转换方法，类比到七进制的实现：
![微信图片_20190826103328_看图王.jpg](https://pic.leetcode-cn.com/29cf7b471f50f4298abc58fc817e72b7acefa6a10f3a3d00fd3e7e3a5e71c75a-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20190826103328_%E7%9C%8B%E5%9B%BE%E7%8E%8B.jpg)
当最后一位小于7时，代表着可以写入新的七进制数，不在进行运算，七进制数为最后的商开始读，由下往上依次读取余数。
算法设计：依次计算num与7的商作为七进制的一位，存储到列表中，num整除7进行更新，直到小于7退出循环。根据短除法可知，此处少了最后的商，两种解决思路：一是改变循环条件，再除一次，此时的余数添加成功，且商一定会变为0，退出循环；二是在循环结束添加商。同时用列表存储的七进制数与真实的七进制数方向正好相反，进行一次简单的调整方向即可。
此处仅考虑了正数，当出现负数时，可将其进行标记后转为负数，最后在列表的最后添加负号在进行调整方向即可。
代码及运行时间如下：
```
class Solution:
    def convertToBase7(self, num: int) -> str:
        base7 = []
        if num < 0:
            flag = 1
            num = -num
        else:
            flag = 0
        while num >= 7:
            fig = str(num % 7)
            base7.append(fig)
            num = num // 7
        base7.append(str(num))
        if flag:
            base7.append('-')
        base7.reverse()
        return ''.join(base7)
```
![微信图片_20190826104600_看图王.png](https://pic.leetcode-cn.com/7567788248d6548e1607455ee82b15b4fbb071b021fe3494b9b1c96d97ab3244-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20190826104600_%E7%9C%8B%E5%9B%BE%E7%8E%8B.png)

