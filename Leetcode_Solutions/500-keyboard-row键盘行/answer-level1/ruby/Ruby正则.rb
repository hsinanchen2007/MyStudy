### 解题思路
正则匹配只含某一行的字母，数量不限，大小写不限

### 代码

```ruby
REG = /^(?:[qwertyuiop]+|[asdfghjkl]+|[zxcvbnm]+)$/i

def find_words(words)
  words.select {|str| str =~ REG }
end
```
执行用时 :36 ms, 在所有 Ruby 提交中击败了100.00%的用户
内存消耗 :9.2 MB, 在所有 Ruby 提交中击败了100.00%的用户