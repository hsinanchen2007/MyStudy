### 解题思路
执行用时 :64 ms, 在所有 Ruby 提交中击败了100.00%的用户
内存消耗 :9.8 MB, 在所有 Ruby 提交中击败了100.00%的用户

### 代码

```ruby
def three_sum_closest(nums, target)
	a = nums.sort
	n = nums.size
	t = target
	d = Float::INFINITY
	s = Float::INFINITY
	i = 0
	while i < n - 2
		x = a[i]
		j = i + 1
		k = n - 1
		while j < k
		  r = x + a[j] + a[k]
		  e = (t - r).abs
		  if e < d
		  	d = e
		  	s = r
		  end
		  case r <=> t
		  when 0  then return t
		  when -1 then j += 1
		  when 1  then k -= 1
		  end
		end
		break if x * 3 > t
		i += 1
	end
	s
end
```