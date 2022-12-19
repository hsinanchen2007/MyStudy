```
def romanToInt(self, s: str) -> int:
        mapping={
            "I":1,
            "V":5,
            "X":10,
            "L":50,
            "C":100,
            "D":500,
            "M":1000
        }
        result = 0
        prev_num = 0
        for c in reversed(s):
            a=mapping.get(c)
            if a < prev_num:
                result -= a
            else:
                result += a
                prev_num = a
        return result

```
参考大神们的神仙代码，自己总结一下思路及知识点
1.正常罗马数字扫描累加即可
2.特殊情况的罗马数字例如IV IX等，都是左边<右边，数值=右边-左边
3.转换思考角度，**从右向左扫描字符串，将每个字符串翻译为数字并进行累加，如果当前字符串小于上一个，则相减，否则相加**
4.注：prev_num为上一字符串的值 prev_num = a是：累加后新的a赋值给prev_num作为下一个数字的上一字符串
5.**关于python字典的注意事项**
（1）值可以取任何数值类型，但键必须是不可变的；如：字符串、数字和元组（列表不可以）
（2）不允许同一个键出现两次，否则后一个值会被记住
（3）其他用法
 
![字典.png](https://pic.leetcode-cn.com/6e2e7f5e8813cc4acfeaefd4a266585139d548e030ff6ca0c4ce1aa136f200e5-%E5%AD%97%E5%85%B8.png)
6.关于python的**循环结构（for-in）**
  常用于遍历字符串、列表，元组，字典等
  此处遍历字典：**遍历字典时遍历的是键**
7.关于reversed()
  上一题解复习了用法，这次需要强调的是其**参数可以是列表，元组，字符串**，此题中反转的是键的字符串，一开始我用的mapping，导致了报错。