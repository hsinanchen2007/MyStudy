### 解题思路
答案是试出来的，使用s.chars进行排序才可以

### 代码

```ruby
# @param {String} s1
# @param {String} s2
# @return {Boolean}
def check_permutation(s1, s2)
        return s1.chars.sort == s2.chars.sort 
end
```