ruby one-line solution
```ruby
def find_repeat_number(nums)
    nums.group_by(&:itself).map { |k, v| v.size > 1 ? [k] + [v.size] : nil}.compact.sort_by(&:last).map(&:first)[0]
end
```
