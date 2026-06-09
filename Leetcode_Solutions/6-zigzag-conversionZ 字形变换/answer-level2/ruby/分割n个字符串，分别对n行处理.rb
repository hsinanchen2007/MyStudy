### 解题思路
此处撰写解题思路

由分析可知，当排为n行时，每次n的单数倍数会触底，2n整除的会触顶，我们只需要保存n个字符串最后拼接即可

故遍历一下字符串，当index为能被n整除时，如果被整除的是2n 就是触顶，被整除的为n即触底，将对应位置的字符拼接到首尾字符串里

当在中间时，可以判断除以n以后的值如果为偶数倍说明是触顶以后向下的位置，如果是奇数说明是触底以后向上移动的情况，然后通过求余可以得到在这n行中的index，执行append

最终得到了n个字符串，for循环一遍历执行append返回即可

### 代码

```ruby
# @param {String} s
# @param {Integer} num_rows
# @return {String}
def convert(s, num_rows)
    if s.length() == 1 || num_rows == 1
        return s
    end
    subStrings = Array.new(num_rows,"")

    for i in 0..s.length()-1
        if i % (num_rows - 1) == 0
            if  i % ((num_rows - 1) * 2) == 0
                #说明触顶
                subStrings[0] += s[i,1]
            #说明触底
            else
                subStrings[num_rows - 1] += s[i,1]
            end
        else
            #说明是触顶以后的操作，向下
            if (i / (num_rows - 1)) % 2 == 0
                subStrings[i % (num_rows - 1)] += s[i,1]
            else#说明是触底以后向上
                subStrings[num_rows - 1 - i % (num_rows - 1)] += s[i,1]
            end
        end
    end

    retString = ''

    for i in 0..num_rows-1
        retString += subStrings[i]
    end

    return retString
end
```