# ![leetcode.png](https://pic.leetcode-cn.com/cdc32fc07d5e209c1d6235f8ae0a9e926f3d2a1bb07c6d81092df4cf9bf7b192-leetcode.png)
# ⏲阅读大约需要3min
# 🔑介绍了正则表达式 (Regular expression, RE) 的基础知识、Python 中 re 模块使用、解题思路
# # ❓什么是正则表达式
# 正则表达式（英语：Regular Expression，常简写为 regex、regexp 或 RE），又称正则表示式、正则表示法、规则表达式、常规表示法，是计算机科学的一个概念。正则表达式使用单个字符串来描述、匹配一系列符合某个句法规则的字符串。
# **❗❗正则表达式通常被用来测试字符串内的模式、替换那些符合某个模式的文本、基于模式匹配从字符串中提取子字符串**

# 由于 re 有很多细节，具体的就不在这里全部写出来了，大家可以参考下面的链接自行复习查缺补漏
# 🧀知识库：
# 1. [https://www.runoob.com/regexp/regexp-tutorial.html](https://www.runoob.com/regexp/regexp-tutorial.html)
# 2. [https://www.liaoxuefeng.com/wiki/1016959663602400/1017639890281664](https://www.liaoxuefeng.com/wiki/1016959663602400/1017639890281664)
# 3. [https://github.com/ziishaned/learn-regex](https://github.com/ziishaned/learn-regex)

# 📜练习网址：
# 1. [https://regexr.com/](https://regexr.com/)
# 2. [https://jex.im/regulex/](https://jex.im/regulex/#!flags=&re=%5E(a%7Cb)*%3F%24)

# 🎈主要还是说一下本题用到的 re 知识点：

# ```
第一组：
" * " 匹配前面的子表达式零次或多次
" + " 匹配前面的子表达式一次或多次
" ？ " 匹配前面的子表达式零次或一次

第二组：
" [abc]" ：方括号表示字符集合，例子表示一个字符串有一个 "a" 或 "b" 或 "c" 等价于 [z|b|c]
" [^abc]"：^表示一个字符串中不应该出现某些模式，即匹配未包含该集合的任意字符
下面几个个也常用
" [a-z]"： 表示一个字符串中存在一个 a 和 z 之间的所有字母
" [0-9]"： 表示一个字符串中存在一个 0 和 9 之间的所有数字
" [^a-z]" ：表示一个字符串中不应该出现 a 到 z 之间的任意一个字母

第三组：
" \d " 匹配一个数字字符，等价[0-9]
" \D " 匹配一个非数字字符，等价[^0-9]
" \w" 匹配包括下划线的任何单词字符。等价于“[A-Za-z0-9_]”
" \W" 匹配任何非单词字符。等价于“[^A-Za-z0-9_]”

第四组：
下面是一些常见使用场景的 pattern
Email 地址：^\w+([-+.]\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*$

手机号码：^(13[0-9]|14[5|7]|15[0|1|2|3|5|6|7|8|9]|18[0|1|2|3|5|6|7|8|9])\d{8}$

ID 号码(数字、字母x结尾)：^([0-9]){7,18}(x|X)?$ 或 ^\d{8,18}|[0-9x]{8,18}|[0-9X]{8,18}?$

密码(以字母开头，长度在 6~18 之间，只能包含字母、数字和下划线)：^[a-zA-Z]\w{5,17}$

强密码(必须包含大小写字母和数字的组合，不能使用特殊字符，长度在8-10之间)：^(?=.*\d)(?=.*[a-z])(?=.*[A-Z]).{8,10}$  

日期格式：^\d{4}-\d{1,2}-\d{1,2}
# ```

# 🐍然后说一下Python种re模块的相关使用：

# 🔶 re.match函数：尝试从字符串的**起始位置**匹配一个模式，如果不是起始位置匹配成功的话，match()就返回none。
# ```python3
re.match(pattern, string, flags=0)
# ```

# 🔶 re.search方法：re.search 扫描整个字符串并返回第一个成功的匹配。
# ```python3
re.search(pattern, string, flags=0)
# ```
# 🔶对于返回的匹配的值，可以使用group(num)匹配对象函数来获取匹配表达式
# 例：
# ```python3
import re
 
line = "We are the best."
# .* 表示任意匹配除换行符（\n、\r）之外的任何单个或多个字符
matchObj = re.match( r'(.*) are (.*?) .*', line, re.M|re.I)
 
if matchObj:
   print ("matchObj.group() : ", matchObj.group())
   print ("matchObj.group(1) : ", matchObj.group(1))
   print ("matchObj.group(2) : ", matchObj.group(2))
else:
   print ("No match!!")
# ```
# 输出：
# ```
matchObj.group() :  We are the best.
matchObj.group(1) :  We
matchObj.group(2) :  the
# ```
# # 🐼代码部分
# ```python3
class Solution:
    def myAtoi(self, str: str) -> int:
        import re
        matches = re.match('[ ]*([+-]?\d+)', str)  # 最重要的就是这一句了吧，正则重在搞定匹配的pattern
        if matches:
            res = int(matches.group(1))
            if res > (MAX := 2 ** 31 - 1):
                return MAX
            elif res < (MIN := -2 ** 31):
                return MIN
            else:
                return res
        else:
            return 0
# ```
# **如果你喜欢这条题解的话，欢迎点赞**👍 **收藏**🧡 **转发**📧 **评论**💬
# **你的鼓励是我持续创作的动力**
# **(゜-゜)つロ 干杯~**

# # 🎈最后插播一条广告，**优秀的你怎可错过！**
# 欢迎加入[@fuxuemingzhu](/u/fuxuemingzhu/)大佬创建的**打卡网站**＆**微信打卡群**
# 你能收获什么：
# - ✅一群志同道合的小伙伴：与 **280**+ 位小伙伴督促打卡，共同进步
# - ✅良好的问答氛围：有问必答，没准还能收获新知识
# - ✅和刷题大佬们一起玩耍：负雪明烛[@fuxuemingzhu](/u/fuxuemingzhu/)、weiwei哥[@liweiwei1419](/u/liweiwei1419/)、甜姨[@sweetiee](/u/sweetiee/)都在群里

# 就差你了，赶快加入，一起来玩耍吧！
# 加群方式见网站👉[http://group.ojeveryday.com/](http://group.ojeveryday.com/)