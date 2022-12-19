参照官方正解的ruby版本, 哈，估计是用ruby的太少了，所以貌似效率很好
> 执行用时 :84 ms, 在所有 Ruby 提交中击败了95.38%的用户
> 内存消耗 :9.2 MB, 在所有 Ruby 提交中击败了100.00%的用户

```ruby
# @param {String} s
# @return {Integer}
def length_of_longest_substring(s)
    str_hash = {}
    i = 0
    j = 0 
    ans = 0
    while i < s.length && j < s.length do 
        if str_hash.key?(s[j])
            i = [i, str_hash[s[j]]].max
        end
        ans = [ans, j - i + 1].max
        str_hash[s[j]] = j + 1
        j = j + 1
    end
    return ans
end
```
