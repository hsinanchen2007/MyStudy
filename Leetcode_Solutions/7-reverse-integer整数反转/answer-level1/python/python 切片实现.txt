### 解题思路
此处撰写解题思路
"""一个看上去很简单的的逻辑，提交的时候，漏洞百出，对 coding 保持敬畏之心"""
使用 python的str 的切片功能，temp_str[::-1] 直接倒叙输出
1、检查输入参数的范围，和转换为 str 是否为空值
2、判断是否是负数-，如果负数,将第一个字符先去掉，
3、temp_str[::-1] 直接倒叙输出，判断倒叙后的值是否在合法范围内
4、如果负数，最后倒叙后在加上’-‘

遇到的坑：
1、超时问题，判断输入参数范围的时候我刚开始写的是 if x not in xrange(-2147483648,2147483648),xrange特别耗时
2、temp_str[::-1] 直接倒叙输出，temp_str[2:-1]是输出第 3 个到倒数第 2 个范围内的字符串
*3、倒叙后的值没有判断在合法范围内*
4、最后忘记转换为 int 类型 return int(item_2)

### 代码

```python
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x >= 2147483648 or x <= -2147483648:
            print "over  %d" % x
            return 0
        item = str(x)
        if not item:
            return None
        if item[0] == '-':
            length = len(item)
            temp_str = item[1:length]
            item_2 = temp_str[::-1]
            if int(item_2) >= 2147483648:
                item_2 = 0
            else: 
                item_2 = ’-‘ + item_2
        else:
            item_2 = item[::-1]
            if int(item_2) >= 2147483648:
                item_2 = 0
        return int(item_2)


        
```