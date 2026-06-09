Ruby 解法还是很简单的
这个子集求法就是
空集也是子集：所以一开始就给了一个这样的 [[]]
第一次考虑都是 1 个数的情况: `nums.combination(1)`
第二次考虑都是 2 个数的情况: `nums.combination(2)`
...
...
第n次考虑都是 n 个数的情况: `nums.combination(n)` 其实就是自己
```ruby
# @param {Integer[]} nums
# @return {Integer[][]}
def subsets(nums)
    res = [[]]
    (1..nums.length).each do |i|
      nums.combination(i).each do |itm|
        res << itm
      end
    end
    res
end
```