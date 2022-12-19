```
# @param {String} s
# @return {Integer}
def longest_palindrome(s)
  # 统计每个字符的个数
  char_count = Hash.new(0)
  s.each_char { |c| char_count[c] += 1 }
  # 最终的回文串最多只能出现一个奇数的字符，其它奇数都要丢弃一个字符后参数回文串的组成
  has_odd = false;
  max = 0;
  char_count.each_value { |v| 
    max += v % 2 == 0 ? v : v - 1
    has_odd |= v % 2 == 1
  }
  return max + (has_odd ? 1 : 0)
end
```
