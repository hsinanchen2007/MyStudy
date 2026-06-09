### 解题思路
ruby one-line solution

### 代码

```ruby
# @param {Integer[]} a
# @return {Integer}
def repeated_n_times(a)
    a.find{ |num| a.count(num) == a.size / 2}
end
```