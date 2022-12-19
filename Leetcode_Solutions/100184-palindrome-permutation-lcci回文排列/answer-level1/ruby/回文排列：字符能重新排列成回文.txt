### 解题思路
#首先理清楚题目，我也是参考大家的
#定义一个数组，将s遍历一次，未包含在数组中的元素，添加进数组，存在数组中的元素则删除掉
#最后数组a存的是总个数为奇数的字符，偶数个数的字符将会消除；偶消奇不消
#判断a.length 的长度是否为小于2   使用item.to_s，  不使用to_i，否则会存在问题
### 代码

```ruby
# @param {String} s
# @return {Boolean}
#总数为奇数的字符最多只有一个
def can_permute_palindrome(s)
    if s.empty?
        return false
    else
       a=[]
        s.chars.each do |item|
            if a.include?(item.to_s)
               a.delete(item.to_s)
            else 
               a.push(item.to_s)
            end
        end
        return a.length  < 2 
    end
     
end
```

