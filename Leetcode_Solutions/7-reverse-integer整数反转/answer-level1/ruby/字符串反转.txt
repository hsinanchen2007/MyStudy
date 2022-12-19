数字转字符串，注意正负号判断大小和范围即可
```
# @param {Integer} x
# @return {Integer}
def reverse(x)
  r = reverse_string(x)
  return 0 if r >= 2**31
  return (-r) if x < 0
  r
end

def reverse_string(x)
  x.to_s.reverse.to_i
end
```
