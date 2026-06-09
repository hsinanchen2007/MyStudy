### 解题思路
Δt > d时，sum += d，否则，sum += Δt
描述为 s += (a[i + 1] - a[i] > d ? d : a[i + 1] - a[i])
其他的就是正常迭代

执行用时 :52 ms, 在所有 Ruby 提交中击败了100.00%的用户
内存消耗 :12.1 MB, 在所有 Ruby 提交中击败了100.00%的用户

### 代码

```ruby
def find_poisoned_duration(a, d)
  return 0 if a.empty?
  n = a.size
  s = 0
  i = 0
  while i < n - 1 # O(n)
    s += (a[i + 1] - a[i] > d ? d : a[i + 1] - a[i])
    i += 1
  end
  s + d
end
```