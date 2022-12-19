# 版本1.0
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        x_list = list(str(abs(x)))    //将输入整数X转换为字符串列表x_list  abs函数表绝对值
        y_list = []   
        i = len(x_list) - 1           //倒叙遍历列表x_list,将新元素转存到新列表y_list
        while i >=0:
          y_list.append(x_list[i])    //append函数会在数组后加入相应的元素
          i -= 1
        if x > 0:
          x_int = int(''.join(y_list))
        else:
          x_int = -(int(''.join(y_list)))//将列表y_list转换为输出整数x_list,并根据x的正负还原符号
        if x_int < -(2 ** 31) or x_int > (2 ** 31 -1)://范围，溢出返回0
            return 0
        return x_int                  //不溢出，返回x_int


1、join()函数
语法：  'sep'.join(seq)
参数说明
sep：分隔符。可以为空
seq：要连接的元素序列、字符串、元组、字典
上面的语法即：以sep作为分隔符，将seq所有的元素合并成一个新的字符串
返回值：返回一个以分隔符sep连接各个元素后生成的字符串
2.append函数
![append.png](https://pic.leetcode-cn.com/3991180ca89f8a4e91f07ad365c2b7b451ead1d9a23ef70a7d842ef0a3cdd9a4-append.png)

# 优化1.1
```
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        x_list = list(str(abs(x)))  
        x_list.reverse()
        if x > 0:
          y = int(''.join(x_list))
        else:
          y = -(int(''.join(x_list)))
        if y < -(2 ** 31) or y > (2 ** 31 -1):
            return 0
        return y
```
1.将输入整数X转换为字符串列表x_list 
2.reverse()方法，反向x_list的元素
3.将列表x_list转换为输出整数y，并根据x的正负还原符号
4.输出整数y的范围，若溢出，返回0
5.不溢出，返回y
6.关于reverse
  是python中列表的一个内置方法（也就是说，在字典，字符串或者元组中，是没有这个内置方法的），用于列表中数据的反转；
7.关于reversed
  reversed()是python自带的一个方法，准确说，应该是一个类;在经过reversed()的作用之后，返回的是一个把序列值经过反转之后的迭代器，所以，需要通过遍历，或者List,或者next()等方法，获取作用后的值；
![reversed.png](https://pic.leetcode-cn.com/949b3c4e7035f39bd3c9356d709ec7c81af0889d0a7aff02fcedf980b5ae1bfd-reversed.png)
# 版本2.0
```
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        temp = abs(x)
        y = 0
        i = len(str(temp))
        while i > 0:
            y = y * 10 + temp % 10
            temp //=10
            i -=1
        if x < 0:
          y = -y
        if y < -(2 ** 31) or y > (2 ** 31 -1):
            return 0
        return y
```
1.循环弹出输入整数x的最后一位，累加至新整数y
2.根据x的正负还原y的符号
3.....范围
4.一切的一切归根结底都是算法，万里长征，希望能够每天坚持----致自己