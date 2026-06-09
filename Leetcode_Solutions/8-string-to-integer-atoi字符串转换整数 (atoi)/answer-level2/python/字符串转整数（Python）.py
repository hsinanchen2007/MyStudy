
![qq_pic_merged_1558151572413.jpg](https://pic.leetcode-cn.com/474a36919a51f975392d09652a917d5ef42e62324bb5b48911ffdb4ac83421ae-qq_pic_merged_1558151572413.jpg)
至于各种分类情况我再强调一些细节，因为本题考查的也是各种情况的全面性。
1. 首字符为"+", "-"符号，需要用标志符记录下来；
2. 首字符为字母或其它非数字以及"+", "-"符号，说明当前字符串不合标准，立即退出返回0；
3. 其他位置上只要不是数字，也立即退出返回前面得到的符合标准的字符串；
这儿有一种情况是题目中没有给出的，刷题时报错了，所以就想分享一下。就是类似于"3.1415"这样的浮点数，结果是'3"，也就是说结果只识整数，不转化浮点数。
代码如下：
```python
class Solution:
    # 此题还需注意的就是类似于3.1415的浮点数的出现了
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        # 首先将给定字符串以空格符切分
        str_split = str.split()
        if len(str_split) == 0:
            return 0
        # 我们只需要考虑str_split[0]即可
        detect_str = str_split[0]
        # 分别定义选取字符串转为整数的起始和终止下标值
        start = 0
        end = 0
        # 定义标志符来区分首字符是否为“+”“-”；“+”用1来表示，反之用-1表示
        flag = 1
        for index in range(len(detect_str)):
            # 如果首字符为“+”“-”，则我们相应改变flag的值，并且都将start与end的值相应+1
            if index == 0 and detect_str[index] in ["-", "+"]:
                flag = 1 if detect_str[index] == "+" else -1
                start += 1
                end += 1
            # 如果当前字符为字母，立即退出
            elif detect_str[index].isdigit():
                end += 1
            # 其它的各种情况均不符合，立即退出 
            else:
                break
        # 通过start与end的值得到我们需要的整数，此处注意正负号
        new_num = int(detect_str[start:end])*flag if start < end else 0
        # 最后的结果别忘了其取值范围是[-2**31, 2**31-1]
        return min(new_num, 2**31-1) if new_num >= 0 else max(new_num, -2**31)


if __name__ == "__main__":
    init_str = "3.14159"
    str_to_int = Solution().myAtoi(init_str)
    print(str_to_int)
```
执行效率出奇的高，达到了100%

![image.png](https://pic.leetcode-cn.com/8c2c2522937b7735644b948a5fccd0091482459c06492195863627d59c2e7eab-image.png)