### 解题思路
分别筛选偶数和奇数元素拼接返回。

### 代码

```ruby
# @param {Integer[]} nums
# @return {Integer[]}
def exchange(nums)
    nums.select{ |n| n.odd? } + nums.select { |n| n.even? }
end
```