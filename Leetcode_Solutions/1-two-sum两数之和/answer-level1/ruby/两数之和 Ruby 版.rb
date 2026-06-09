
1. 暴力法

```ruby
def two_sum(nums, target)
  nums.each_with_index do |e, i|
    pi = nums.index(target - e)
    return [i, pi] if pi && pi != i
  end
end
```

2. 哈希

```ruby 
def two_sum(nums, target)
   map = {}

   nums.each_with_index do |e, i|
    return [map[e], i] if map.has_key?(e)
    map[target - e] = i
   end
end
```