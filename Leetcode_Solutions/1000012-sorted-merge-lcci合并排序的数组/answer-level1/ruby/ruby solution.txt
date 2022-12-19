### 解题思路
ruby solution
sort! in-place修改

### 代码

```ruby
# @param {Integer[]} a
# @param {Integer} m
# @param {Integer[]} b
# @param {Integer} n
# @return {Void} Do not return anything, modify A in-place instead.
def merge(a, m, b, n)
    i = 0
    while i < n
        a[i + m] = b[i]
        i += 1
    end
    a.sort!     
end
```