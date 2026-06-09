### 解题思路
同题解思路二

执行用时 :48 ms, 在所有 Ruby 提交中击败了100.00%的用户
内存消耗 :9.8 MB, 在所有 Ruby 提交中击败了100.00%的用户

### 代码

```ruby
def merge(intervals)
    return intervals if intervals.empty?
	n = intervals.sort_by{|a| a[0] } # O(logn)
	a = [n[0]]
	i = 0
	j = 1
	while j < n.size # O(n)
		x = a[i]
		y = n[j]
		if y[0] > x[1]
			a << y
			i += 1
		else
			a[i][1] = [x[1], y[1]].max
		end
		j += 1
	end
	a
end
```