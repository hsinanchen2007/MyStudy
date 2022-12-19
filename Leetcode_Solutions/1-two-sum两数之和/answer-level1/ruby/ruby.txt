# ruby
```
def two_sum(nums, target)
   	map = {}
	nums.each_with_index {|x, j| map[target - x] = j} 
	nums.each_with_index {|s, y| return [y, map[s]] if map[s] and y != map[s]}
        
end
```
