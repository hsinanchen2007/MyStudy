### 解题思路
当字符串长度为0或1时，不存在前缀，直接返回空字符串。


由于ruby的字符串处理非常的慢，每一次取字符都会生成新对象，
因此从一开始就生成了最长的prefix也就是`s[0, s.size - 1]`，之后再原地修改。

每一次迭代，直接判断`s.start_with?(part) && s.end_with?(part)`
由于从最长的开始比较，一旦满足条件则直接返回当前part，即为最长前缀。
最差的情况下，一直迭代到part为空才能出结果，返回空字符串。

### 代码

```ruby
def longest_prefix(s)
  return '' if s.size < 2
  part = s[0, s.size - 1]
  while !part.empty?
    if s.start_with?(part) && s.end_with?(part)
      return part
    end
    part.chop!
  end
  ''
end
```

执行用时 :1000 ms, 在所有 Ruby 提交中击败了100.00%的用户
内存消耗 :15.2 MB, 在所有 Ruby 提交中击败了100.00%的用户